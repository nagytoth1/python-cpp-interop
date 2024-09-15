#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <random>
#include <stdexcept>

int add(int a, int b) { return a + b; }
int multiply_two_ints(int a, int b) { return a * b; }
std::vector<int> generate_numbers(unsigned int quantity, int lower_bound, int upper_bound)
{
    if (quantity < 1)
    {
        throw std::invalid_argument("Invalid arguments for generate_numbers. The number of elements must be greater or equal to 1.");
    }
    if (lower_bound >= upper_bound)
    {
        throw std::invalid_argument("Invalid arguments for generate_numbers. 'lower_bound' must be less than 'upper_bound'.");
    }

    // Prepare the random number generator and distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(lower_bound, upper_bound);

    // Generate numbers directly using a lambda function
    std::vector<int> generated_numbers(quantity);
    for (auto &num : generated_numbers)
    {
        num = distrib(gen);
    }

    return generated_numbers;
}

PYBIND11_MODULE(calculations_cpp, m)
{
    m.def("add", &add);
    m.def("multiply_two_ints", &multiply_two_ints);
    m.def("generate_numbers", &generate_numbers);
}