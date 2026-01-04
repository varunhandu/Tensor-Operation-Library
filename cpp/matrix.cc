#include "matrix.h"
#include <stdexcept>

std::vector<std::vector<double>> matmul(
    const std::vector<std::vector<double>>& a,
    const std::vector<std::vector<double>>& b
) {
    if (a.empty() || b.empty() || a[0].size() != b.size()) {
        throw std::invalid_argument("Invalid matrix dimensions");
    }

    size_t n = a.size();
    size_t m = b[0].size();
    size_t k = b.size();

    std::vector<std::vector<double>> result(
        n, std::vector<double>(m, 0.0)
    );

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            for (size_t t = 0; t < k; ++t)
                result[i][j] += a[i][t] * b[t][j];

    return result;
}