#pragma once

#include <cstddef>
#include <memory>
#include <vector>
#include <stdexcept>

namespace tensor_core {

class TensorBuffer {
public:
    using value_type = double;

    TensorBuffer(std::vector<size_t> shape);

    value_type* data();
    const value_type* data() const;

    const std::vector<size_t>& shape() const;
    const std::vector<size_t>& strides() const;

    size_t ndim() const;
    size_t numel() const;

private:
    std::shared_ptr<value_type[]> data_;
    std::vector<size_t> shape_;
    std::vector<size_t> strides_;

    static std::vector<size_t> compute_strides(const std::vector<size_t>& shape);
};

} // namespace tensor_core
