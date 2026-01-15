#pragma once

#include "core/tensor_view.h"

namespace tensor_core {

void add_kernel(
    const TensorView& a,
    const TensorView& b,
    TensorView& out
);

} // namespace tensor_core

