#pragma once

#include "expr/expr.h"
#include <cstddef>
#include <memory>
#include <vector>

namespace tensor_core {

class Tensor {
public:
    // Construct from concrete data
    explicit Tensor(std::shared_ptr<TensorBuffer> buffer);

    // Construct from expression
    explicit Tensor(Expr expr);

    TensorView eval() const;

    const std::vector<size_t>& shape() const;

    // Operators - To be implemented
    Tensor operator+(const Tensor& other) const;
    Tensor matmul(const Tensor& other) const;
    Tensor transpose(size_t dim1, size_t dim2) const;

private:
    // Exactly one of these is active
    std::shared_ptr<TensorBuffer> buffer_;
    Expr expr_;

    mutable std::shared_ptr<TensorView> cached_view_;
};

} // namespace tensor_core
