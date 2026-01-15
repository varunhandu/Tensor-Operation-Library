#include "core/tensor_buffer.h"

#include <numeric>
#include <stdexcept>

namespace tensor_core {

TensorBuffer::TensorBuffer(std::vector<size_t> shape)
    : shape_(std::move(shape)) {

    if (shape_.empty()) {
        throw std::runtime_error("TensorBuffer: shape cannot be empty");
    }

    strides_ = compute_strides(shape_);

    size_t total = numel();
    data_ = std::shared_ptr<value_type[]>(
        new value_type[total](),
        std::default_delete<value_type[]>()
    );
}

TensorBuffer::value_type* TensorBuffer::data() {
    return data_.get();
}

const TensorBuffer::value_type* TensorBuffer::data() const {
    return data_.get();
}

const std::vector<size_t>& TensorBuffer::shape() const {
    return shape_;
}

const std::vector<size_t>& TensorBuffer::strides() const {
    return strides_;
}

size_t TensorBuffer::ndim() const {
    return shape_.size();
}

size_t TensorBuffer::numel() const {
    return std::accumulate(
        shape_.begin(),
        shape_.end(),
        size_t{1},
        std::multiplies<size_t>()
    );
}

std::vector<size_t>
TensorBuffer::compute_strides(const std::vector<size_t>& shape) {
    std::vector<size_t> strides(shape.size());

    size_t stride = 1;
    for (int i = static_cast<int>(shape.size()) - 1; i >= 0; --i) {
        strides[i] = stride;
        stride *= shape[i];
    }

    return strides;
}

} // namespace tensor_core
