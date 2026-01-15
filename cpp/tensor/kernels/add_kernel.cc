#include "kernels/add_kernel.h"
#include <cstddef>

namespace tensor_core {

void add_kernel(
    const TensorView& a,
    const TensorView& b,
    TensorView& out
) {
    const auto& shape = a.shape();
    const auto& a_strides = a.strides();
    const auto& b_strides = b.strides();
    const auto& out_strides = out.strides();

    double* out_data = out.data();
    const double* a_data = a.data();
    const double* b_data = b.data();

    const size_t ndim = shape.size();

    // Flat index iteration (simple & correct first)
    size_t total = out.numel();

    for (size_t idx = 0; idx < total; ++idx) {
        size_t tmp = idx;

        size_t a_offset = 0;
        size_t b_offset = 0;
        size_t out_offset = 0;

        for (int d = ndim - 1; d >= 0; --d) {
            size_t coord = tmp % shape[d];
            tmp /= shape[d];

            a_offset += coord * a_strides[d];
            b_offset += coord * b_strides[d];
            out_offset += coord * out_strides[d];
        }

        out_data[out_offset] =
            a_data[a_offset] + b_data[b_offset];
    }
}

} // namespace tensor_core
