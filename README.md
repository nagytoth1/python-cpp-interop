## How to build C++ module calculations_cpp?

Starting from this project's root directory use the following commands (Linux only):

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

And done, you have built the `calculations_cpp` module successfully!
Since the CMakeLists.txt configuration contains the creation of a `__init__.py` script, Python will treat it as a Python package so it can be used now.

The `main.py` script demonstrates the call of C++ functions.

Using mypy package we can utilize `stubgen` command to make a stub for the package to have the benefits of type hinting and intellisense in Python.

```bash
# generate calculations_cpp.pyi into the build directory
stubgen -m build.calculations_cpp -o .
```
