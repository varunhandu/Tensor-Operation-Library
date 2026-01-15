#pragma once

#include "expr/expr.h"
#include "core/tensor_view.h"
#include <memory>

namespace tensor_core {

class BufferExprNode : public ExprNode {
public:
    explicit BufferExprNode(std::shared_ptr<TensorBuffer> buffer)
        : buffer_(std::move(buffer)) {}

    TensorView eval() override {
        return TensorView::from_buffer(buffer_);
    }

    const std::vector<size_t>& shape() const override {
        return buffer_->shape();
    }


private:
    std::shared_ptr<TensorBuffer> buffer_;
};

} // namespace tensor_core
