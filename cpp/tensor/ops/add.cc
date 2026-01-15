#include "core/tensor.h"
#include "expr/add_expr.h"
#include "expr/expr.h"
#include "expr/buffer_expr.h"

#include <stdexcept>

namespace tensor_core {

Tensor Tensor::operator+(const Tensor& other) const {
    // Case 1: both tensors already have concrete buffers
    // We still create a lazy expression
    Expr lhs_expr;
    Expr rhs_expr;

    if (expr_) {
        lhs_expr = expr_;
    } else if (buffer_) {
        lhs_expr = std::make_shared<BufferExprNode>(buffer_);
    } else {
        throw std::runtime_error("Invalid Tensor state (lhs)");
    }

    if (other.expr_) {
        rhs_expr = other.expr_;
    } else if (other.buffer_) {
        rhs_expr = std::make_shared<BufferExprNode>(other.buffer_);
    } else {
        throw std::runtime_error("Invalid Tensor state (rhs)");
    }

    Expr add_expr = std::make_shared<AddExprNode>(lhs_expr, rhs_expr);
    return Tensor(add_expr);
}

} // namespace tensor_core
