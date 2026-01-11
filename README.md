# Explicit Tensor Core

## Aim
* Build a library, which makes tensor computations more clear
* Anti-thesis to Abstracted Tensor Operations
* Operations need to be intentional

## Current Aim
* Create a Base Tensor Implementation
* Perform Matrix operations

## How to run (because I keep forgetting)
From the root directory run the following commands
* `bazel build //cpp:matrix_py`
* `bazel run //python:main`
* run `bazel clean --expunge` if you want to clean the cache