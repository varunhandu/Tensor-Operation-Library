load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "matrix_lib",
    srcs = ["matrix.cc"],
    hdrs = ["matrix.h"],
    copts = ["-std=c++20"],
)

cc_binary(
    name = "matrix_py",
    srcs = ["matrix_pybind.cc"],
    deps = [
        ":matrix_lib",
        "@pybind11//:pybind11",
        "@python_3_12//:python_headers",
    ],
    copts = ["-std=c++20", "-fPIC"],
    linkshared = True,
    linkopts = ["-Wl,-soname,matrix_py.so"],
    visibility = ["//visibility:public"],
)

genrule(
    name = "matrix_py_so",
    srcs = [":matrix_py"],
    outs = ["matrix_py.so"],
    cmd = "cp $(location :matrix_py) $@",
    visibility = ["//visibility:public"],
)