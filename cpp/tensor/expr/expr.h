#pragma once

#include "core/tensor_view.h"
#include <memory>

namespace tensor_core {

class ExprNode {
public:
    virtual ~ExprNode() = default;

    virtual TensorView eval() = 0;
    virtual const std::vector<size_t>& shape() const = 0;
};

using Expr = std::shared_ptr<ExprNode>;

} // namespace tensor_core
