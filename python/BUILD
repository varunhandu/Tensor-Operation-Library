load("@rules_python//python:defs.bzl", "py_library", "py_binary")

py_binary(
    name = "main",
    srcs = ["main.py"],
    data = [
        "//cpp/tensor/pybind:tensor_py_so",
    ],
    imports = ["."],
    deps = [
        "@pip_deps//numpy",
    ],
)
