#pragma once

#include "expr/expr.h"
#include "core/tensor_buffer.h"
#include "core/tensor_view.h"
#include <memory>

namespace tensor_core {

class AddExprNode : public ExprNode {
public:
    AddExprNode(Expr lhs, Expr rhs);

    TensorView eval() override;
    const std::vector<size_t>& shape() const override;

private:
    Expr lhs_;
    Expr rhs_;
    std::vector<size_t> shape_;
};

} // namespace tensor_core
