#include <pybind11/pybind11.h>
#include "tensor_bindings.h"
#include "op_bindings.h"

namespace py = pybind11;

PYBIND11_MODULE(tensor_py, m) {
    auto tensor_class = tensor_py::bind_tensor(m);
    bind_ops(tensor_class);
}
