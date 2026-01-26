#pragma once
#include <pybind11/pybind11.h>
#include "core/tensor.h"

namespace tensor_core {
class Tensor;
}

void bind_ops(pybind11::class_<tensor_core::Tensor>& cls);