load("@rules_python//python:defs.bzl", "py_library", "py_binary")

genrule(
    name = "matrix_py_ext",
    srcs = ["//cpp:matrix_py_so"],
    outs = ["matrix_py/matrix_py.so"],
    cmd = "cp $(location //cpp:matrix_py_so) $@",
)

py_library(
    name = "matrix_py",
    srcs = ["matrix_py/__init__.py"],
    data = [":matrix_py_ext"],
    visibility = ["//visibility:public"],
    imports = ["."]
)

py_binary(
    name = "main",
    srcs = ["main.py"],
    deps = [":matrix_py"],
)