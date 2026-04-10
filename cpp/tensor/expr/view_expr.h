#include "expr/expr.h"
#include "core/tensor_view.h"
#include <memory>
#include <vector>

namespace tensor_core {
class ViewExprNode : public ExprNode {
public:
    explicit ViewExprNode(TensorView view)
        : view_(std::move(view)) {}

    TensorView eval() const override {
        return view_;
    }

    const std::vector<size_t>& shape() const override {
        return view_.shape();
    }

private:
    TensorView view_;
};
}
