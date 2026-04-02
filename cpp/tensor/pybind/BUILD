load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

cc_library(
    name = "tensor_binding_lib",
    srcs = [
        "tensor_bindings.cc",
        "op_bindings.cc",
    ],
    hdrs = [
        "tensor_bindings.h",
        "op_bindings.h",
    ],
    deps = [
        "//cpp/tensor:tensor_core",
        "@pybind11//:pybind11",
        "@python_3_12//:python_headers",
    ],
    copts = ["-std=c++20", "-fPIC"],
)

cc_binary(
    name = "tensor_py",
    srcs = [
        "tensor_pybind.cc",
    ],
    deps = [
        ":tensor_binding_lib",
        "@pybind11//:pybind11",
    ],
    copts = [
        "-fPIC",
        "-O3",
    ],
    linkopts = [
        "-shared",
    ],
    linkshared = True,
    visibility = ["//visibility:public"],
)

genrule(
    name = "tensor_py_so",
    srcs = [":tensor_py"],
    outs = ["tensor_py.so"],
    cmd = "cp $(location :tensor_py) $@",
    visibility = ["//visibility:public"],
)
