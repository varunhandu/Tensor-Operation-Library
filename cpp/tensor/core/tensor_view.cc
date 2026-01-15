#include "core/tensor_view.h"

#include <memory>
#include <numeric>
#include <stdexcept>

namespace tensor_core {

TensorView::TensorView(
    std::shared_ptr<TensorBuffer> buffer,
    size_t offset,
    std::vector<size_t> shape,
    std::vector<size_t> strides
)
    : buffer_(std::move(buffer)),
      offset_(offset),
      shape_(std::move(shape)),
      strides_(std::move(strides)) {

    if (!buffer_) {
        throw std::runtime_error("TensorView: buffer is null");
    }

    if (shape_.size() != strides_.size()) {
        throw std::runtime_error(
            "TensorView: shape and strides rank mismatch"
        );
    }
}

TensorView TensorView::from_buffer(
    std::shared_ptr<TensorBuffer> buffer
) {
    return TensorView(
        buffer,
        0,                  // offset
        buffer->shape(),
        buffer->strides()
    );
}

TensorView::value_type* TensorView::data() {
    return buffer_->data() + offset_;
}

const TensorView::value_type* TensorView::data() const {
    return buffer_->data() + offset_;
}

std::shared_ptr<TensorBuffer> TensorView::buffer() const {
    return buffer_;
}

const std::vector<size_t>& TensorView::shape() const {
    return shape_;
}

const std::vector<size_t>& TensorView::strides() const {
    return strides_;
}

size_t TensorView::offset() const {
    return offset_;
}

size_t TensorView::ndim() const {
    return shape_.size();
}

size_t TensorView::numel() const {
    return std::accumulate(
        shape_.begin(),
        shape_.end(),
        size_t{1},
        std::multiplies<size_t>()
    );
}

TensorView TensorView::transpose() const {
    if (ndim() != 2) {
        throw std::runtime_error(
            "TensorView::transpose: only 2D tensors supported"
        );
    }

    std::vector<size_t> new_shape = {
        shape_[1],
        shape_[0]
    };

    std::vector<size_t> new_strides = {
        strides_[1],
        strides_[0]
    };

    return TensorView(
        buffer_,
        offset_,
        std::move(new_shape),
        std::move(new_strides)
    );
}

} // namespace tensor_core
