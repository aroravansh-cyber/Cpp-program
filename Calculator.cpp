#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int a, b;
    char op;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter operator (+, -, *): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> b;

    if (op == '+')
        cout << "Result = " << add(a, b);
    else if (op == '-')
        cout << "Result = " << subtract(a, b);
    else if (op == '*')
        cout << "Result = " << multiply(a, b);
    else
        cout << "Invalid operator";

    return 0;
}
