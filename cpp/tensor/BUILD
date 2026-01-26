package(default_visibility = ["//visibility:public"])
load("@rules_cc//cc:defs.bzl", "cc_library")
cc_library(
    name = "tensor_core",
    srcs = glob([
        "core/**/*.cc",
        "expr/**/*.cc",
        "kernels/**/*.cc",
        "ops/**/*.cc",
    ]),
    hdrs = glob([
        "core/**/*.h",
        "expr/**/*.h",
        "kernels/**/*.h",
        # "ops/**/*.h",
    ]),
    includes = [
        ".",                # allows #include "core/tensor.h"
    ],
    copts = [
        "-std=c++17",
        "-O3",
        "-fPIC",             # IMPORTANT: needed for shared libs
    ],
    linkstatic = True,
)
