import os
import sys

sys.path.append(os.getcwd())

from cpp.tensor.pybind import tensor_py


def main():
    print("=== Tensor Core Test ===")

    t1 = tensor_py.Tensor([[1.0, 2.0], [3.0, 4.0]])

    t2 = tensor_py.Tensor([[5.0, 6.0], [7.0, 8.0]])

    print("Tensor 1:", t1.eval())
    print("Tensor 2:", t2.eval())

    t3 = t1 + t2

    print("After addition (lazy, before eval)")

    result = t3.eval()

    print("Result:", result)

    # Expected output check
    expected = [[6.0, 8.0], [10.0, 12.0]]

    print("Expected:", expected)

    # Simple validation
    if result.tolist() == expected:
        print("✅ Test PASSED")
    else:
        print("❌ Test FAILED")

    print("=== Transpose Test ===")
    t4 = tensor_py.Tensor([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]])
    print("Tensor 4:", t4.eval())
    t5 = t4.transpose(0, 1)
    print("After transpose:", t5.eval())
    expected_transpose = [[1.0, 4.0], [2.0, 5.0], [3.0, 6.0]]
    if t5.eval().tolist() == expected_transpose:
        print("✅ Transpose PASSED")
    else:
        print("❌ Transpose FAILED")


# TODO : BUG FIX
# Tensor does not follow stride based indexing correctly
# It needs to be fixed. Currently causing problems in transpose operations.
if __name__ == "__main__":
    main()
