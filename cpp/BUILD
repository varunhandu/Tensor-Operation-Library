package(default_visibility = ["//visibility:public"])

alias(
    name = "tensor_py",
    actual = "//cpp/tensor/pybind:tensor_py",
)

genrule(
    name = "tensor_py_so",
    srcs = [":tensor_py"],
    outs = ["tensor_py.so"],
    cmd = "cp $(location :tensor_py) $@",
    visibility = ["//visibility:public"],
)
