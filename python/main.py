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


if __name__ == "__main__":
    main()
