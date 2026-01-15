#include "core/tensor_buffer.h"
#include "core/tensor_view.h"
#include "core/tensor.h"

#include <iostream>
#include <cassert>

using namespace tensor_core;

int main() {
    // Create buffer A
    auto bufA = std::make_shared<TensorBuffer>(
        std::vector<size_t>{2, 2}
    );

    double* a_data = bufA->data();
    a_data[0] = 1; a_data[1] = 2;
    a_data[2] = 3; a_data[3] = 4;

    Tensor A(bufA);

    // Create buffer B
    auto bufB = std::make_shared<TensorBuffer>(
        std::vector<size_t>{2, 2}
    );

    double* b_data = bufB->data();
    b_data[0] = 10; b_data[1] = 20;
    b_data[2] = 30; b_data[3] = 40;

    Tensor B(bufB);

    // Lazy add
    Tensor C = A + B;

    // Force evaluation
    TensorView out = C.eval();

    const double* out_data = out.data();

    assert(out_data[0] == 11);
    assert(out_data[1] == 22);
    assert(out_data[2] == 33);
    assert(out_data[3] == 44);

    std::cout << "Add test passed! \n";
    return 0;
}