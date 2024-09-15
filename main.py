import build.calculations_cpp as calculations

a = 10
b = 20

result = calculations.add(a, b)
result2 = calculations.multiply_two_ints(a, b)
try:
    result3 = calculations.generate_numbers(5, 1, 10)
    print(f'Generated numbers = {result3}')
except Exception as e:
    print(f'An exception occured: {e}')

print(f'a = {a}, b = {b}, a + b = {result}')
print(f'a = {a}, b = {b}, a * b = {result2}')
