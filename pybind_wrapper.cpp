#include <pybind11/pybind11.h>

int add(int a, int b){return a+b;}
int multiply_two_ints(int a, int b){return a*b;}

PYBIND11_MODULE(simple_module, m){
    m.def("add", &add);
    m.def("multiply_two_ints", &multiply_two_ints);
}