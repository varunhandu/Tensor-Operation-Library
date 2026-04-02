#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include "tensor_bindings.h"
#include "core/tensor.h"
#include "core/tensor_buffer.h"

namespace py = pybind11;
using namespace tensor_core;

namespace tensor_py {

py::class_<Tensor> bind_tensor(py::module_& m) {
    py::class_<Tensor> cls(m, "Tensor");

    cls.def(py::init([](const std::vector<std::vector<double>>& data) {
            return Tensor(std::make_shared<TensorBuffer>(data));
        }))
       .def("eval", [](Tensor& t) {
            auto v = t.eval();
            std::vector<py::ssize_t> shape(v.shape().begin(), v.shape().end());
            std::vector<py::ssize_t> stride(shape.size());

            py::ssize_t curr_stride = sizeof(double);

            for (py::ssize_t i = shape.size() - 1; i >= 0; --i) {
                stride[i] = curr_stride;
                curr_stride *= shape[i];
            }

            return py::array_t<double>(
                shape,
                stride,
                v.data()
            );
        });

    return cls;
}

}
