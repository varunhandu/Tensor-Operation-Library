import importlib.util
import os

package_location = os.path.join(os.path.dirname(__file__), "matrix_py.so")

spec = importlib.util.spec_from_file_location("matrix_py", package_location)
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)

globals().update(module.__dict__)