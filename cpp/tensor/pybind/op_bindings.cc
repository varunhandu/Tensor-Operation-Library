#include <pybind11/pybind11.h>
#include "core/tensor.h"
#include "op_bindings.h"

namespace py = pybind11;
using namespace tensor_core;

void bind_ops(py::class_<Tensor>& cls) {
    cls.def("__add__", &Tensor::operator+);
    // cls.def("matmul", &Tensor::matmul);
    // cls.def("transpose", &Tensor::transpose);
}