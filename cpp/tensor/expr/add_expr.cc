#include "expr/add_expr.h"
#include "kernels/add_kernel.h"
#include <stdexcept>

namespace tensor_core {

AddExprNode::AddExprNode(Expr lhs, Expr rhs)
    : lhs_(std::move(lhs)), rhs_(std::move(rhs)) {
    if (!lhs_ || !rhs_) {
        throw std::runtime_error("AddExprNode: null operand");
    }

    if (lhs_->shape() != rhs_->shape()) {
        throw std::runtime_error("AddExprNode: shape mismatch");
    }

    shape_ = lhs_->shape();
}


const std::vector<size_t>& AddExprNode::shape() const {
    return shape_;
}

TensorView AddExprNode::eval() const {
    TensorView a = lhs_->eval();
    TensorView b = rhs_->eval();

    if (a.shape() != b.shape()) {
        throw std::runtime_error("AddExprNode: shape mismatch");
    }

    auto out_buffer = std::make_shared<TensorBuffer>(a.shape());

    TensorView out = TensorView::from_buffer(out_buffer);

    add_kernel(a, b, out);

    return out;
}

} // namespace tensor_core
