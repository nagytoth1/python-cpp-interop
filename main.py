import build.calculations_cpp as calculations

a = 10
b = 20

result = calculations.add(a, b)
result2 = calculations.multiply_two_ints(a, b)
print(f'a = {a}, b = {b}, a + b = {result}')
print(f'a = {a}, b = {b}, a * b = {result2}')