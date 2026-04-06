#pragma once

#include "core/tensor_buffer.h"
#include "tensor_buffer.h"
#include <memory>
#include <vector>

namespace tensor_core {

class TensorView {
public:
    using value_type = double;

    TensorView(
        std::shared_ptr<TensorBuffer> buffer,
        size_t offset,
        std::vector<size_t> shape,
        std::vector<size_t> strides
    );

    static TensorView from_buffer(std::shared_ptr<TensorBuffer> buffer);
    std::shared_ptr<TensorBuffer> buffer() const;

    value_type* data();
    const value_type* data() const;

    const std::vector<size_t>& shape() const;
    const std::vector<size_t>& strides() const;

    size_t offset() const;
    size_t ndim() const;
    size_t numel() const;

    TensorView transpose(size_t dim1, size_t dim2) const; // can only change shape_ and strides_

private:
    std::shared_ptr<TensorBuffer> buffer_;
    size_t offset_;
    std::vector<size_t> shape_;
    std::vector<size_t> strides_;
};

} // namespace tensor_core
