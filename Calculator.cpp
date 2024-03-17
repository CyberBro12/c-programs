#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Calculator {
private:
    T num1, num2;

public:
    Calculator(T num1, T num2) : num1(num1), num2(num2) {}

    T add() const {
        return num1 + num2;
    }

    T subtract() const {
        return num1 - num2;
    }

    T multiply() const {
        return num1 * num2;
    }

    T divide() const {
        if (num2 == 0) {
            throw runtime_error("Division by zero error");
        }
        return num1 / num2;
    }

    T modulus() const {
        if constexpr (is_integral_v<T>) {
            if (num2 == 0) {
                throw runtime_error("Modulus by zero error");
            }
            return num1 % num2;
        } else {
            throw runtime_error("Modulus operation not supported for floating-point types");
        }
    }
};

int main() {
    try {
        Calculator<double> calc(3.14, 2.71);
        cout << "Addition: " << calc.add() << endl;
        cout << "Subtraction: " << calc.subtract() << endl;
        cout << "Multiplication: " << calc.multiply() << endl;
        cout << "Division: " << calc.divide() << endl;
        cout << "Modulus: " << calc.modulus() << endl;
    } catch (const runtime_error& error) {
        cerr << "Error: " << error.what() << endl;
    }
    return 0;
}
