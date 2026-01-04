#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "matrix.h"

namespace py = pybind11;

PYBIND11_MODULE(matrix_py, m) {
    m.doc() = "Matrix multiplication implemented in C++";

    m.def(
        "matmul",
        &matmul,
        "Multiply two matrices"
    );
}