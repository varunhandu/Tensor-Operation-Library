#pragma once
#include <pybind11/pybind11.h>

namespace tensor_core {
class Tensor;
}


namespace tensor_py {
    pybind11::class_<tensor_core::Tensor> bind_tensor(pybind11::module_& m);
}