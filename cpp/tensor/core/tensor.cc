#include "core/tensor.h"
#include "core/tensor_view.h"
#include "core/tensor_buffer.h"

#include <stdexcept>

namespace tensor_core {

/*
 * Construct Tensor from concrete data (eager tensor)
 */
Tensor::Tensor(std::shared_ptr<TensorBuffer> buffer)
    : buffer_(std::move(buffer)),
      expr_(nullptr),
      cached_view_(nullptr) {

    if (!buffer_) {
        throw std::runtime_error("Tensor: buffer is null");
    }
}

/*
 * Construct Tensor from expression (lazy tensor)
 */
Tensor::Tensor(Expr expr)
    : buffer_(nullptr),
      expr_(std::move(expr)),
      cached_view_(nullptr) {

    if (!expr_) {
        throw std::runtime_error("Tensor: expr is null");
    }
}

/*
 * Force evaluation (materialize data if needed)
 */
TensorView Tensor::eval() {
    // If we already evaluated before, return cached view
    if (cached_view_) {
        return *cached_view_;
    }

    // Case 1: already has concrete buffer
    if (buffer_) {
        cached_view_ = std::make_shared<TensorView>(
            TensorView::from_buffer(buffer_)
        );
        return *cached_view_;
    }

    // Case 2: lazy expression
    if (!expr_) {
        throw std::runtime_error("Tensor::eval: invalid tensor state");
    }

    TensorView view = expr_->eval();

    // Cache result
    buffer_ = view.buffer();
    expr_.reset();

    cached_view_ = std::make_shared<TensorView>(view);
    return view;
}

/*
 * Shape information
 */
const std::vector<size_t>& Tensor::shape() const {
    if (buffer_) {
        return buffer_->shape();
    }

    if (cached_view_) {
        return cached_view_->shape();
    }

    if (expr_) {
        return expr_->shape();
    }

    throw std::runtime_error("Tensor::shape: invalid tensor state");
}

} // namespace tensor_core
