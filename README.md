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
