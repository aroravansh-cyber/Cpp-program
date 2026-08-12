#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// ---------- Basic Operations ----------
double add(double a, double b) {
    return a + b;
}

double subtractNum(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divideNum(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero!\n";
        return NAN;
    }
    return a / b;
}

long long factorial(int n) {
    if (n < 0) return -1;

    long long fact = 1;

    for (int i = 1; i <= n; i++)
        fact *= i;

    return fact;
}

// ---------- Display Menu ----------
void showMenu() {
    cout << "\n============================================\n";
    cout << "        ADVANCED SCIENTIFIC CALCULATOR\n";
    cout << "============================================\n";

    cout << "\n--- Basic Operations ---\n";
    cout << "1.  Addition\n";
    cout << "2.  Subtraction\n";
    cout << "3.  Multiplication\n";
    cout << "4.  Division\n";
    cout << "5.  Modulus\n";
    cout << "6.  Power\n";
    cout << "7.  Square\n";
    cout << "8.  Cube\n";
    cout << "9.  Square Root\n";
    cout << "10. Factorial\n";
    cout << "11. Absolute Value\n";

    cout << "\n--- Scientific Operations ---\n";
    cout << "12. Sin\n";
    cout << "13. Cos\n";
    cout << "14. Tan\n";
    cout << "15. Log10\n";
    cout << "16. Natural Log\n";
    cout << "17. Exponential\n";
    cout << "18. Floor\n";
    cout << "19. Ceiling\n";

    cout << "\n--- Mathematical Tools ---\n";
    cout << "20. Percentage\n";
    cout << "21. Average\n";
    cout << "22. Percentage Increase\n";
    cout << "23. Percentage Decrease\n";
    cout << "24. Quadratic Equation\n";

    cout << "\n--- Financial Calculator ---\n";
    cout << "25. GST Calculator\n";
    cout << "26. Simple Interest\n";
    cout << "27. Compound Interest\n";

    cout << "\n--- Conversions ---\n";
    cout << "28. Celsius to Fahrenheit\n";
    cout << "29. Fahrenheit to Celsius\n";
    cout << "30. Decimal to Binary\n";
    cout << "31. Binary to Decimal\n";

    cout << "\n--- Other ---\n";
    cout << "32. Calculation History\n";
    cout << "33. Clear History\n";
    cout << "34. Exit\n";

    cout << "\n============================================\n";
}

// ---------- Decimal to Binary ----------
string decimalToBinary(int n) {
    if (n == 0)
        return "0";

    string binary = "";

    while (n > 0) {
        binary = char((n % 2) + '0') + binary;
        n /= 2;
    }

    return binary;
}

// ---------- Binary to Decimal ----------
int binaryToDecimal(string binary) {
    int decimal = 0;

    for (char digit : binary) {
        if (digit != '0' && digit != '1')
            return -1;

        decimal = decimal * 2 + (digit - '0');
    }

    return decimal;
}

// ---------- Main ----------
int main() {

    int choice;
    double a, b, result;
    vector<string> history;

    cout << fixed << setprecision(4);

    do {

        showMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            // 1 Addition
            case 1:
                cout << "Enter two numbers: ";
                cin >> a >> b;

                result = add(a, b);

                cout << "Result = " << result << endl;

                history.push_back(
                    to_string(a) + " + " + to_string(b)
                    + " = " + to_string(result)
                );
                break;

            // 2 Subtraction
            case 2:
                cout << "Enter two numbers: ";
                cin >> a >> b;

                result = subtractNum(a, b);

                cout << "Result = " << result << endl;
                break;

            // 3 Multiplication
            case 3:
                cout << "Enter two numbers: ";
                cin >> a >> b;

                result = multiply(a, b);

                cout << "Result = " << result << endl;
                break;

            // 4 Division
            case 4:
                cout << "Enter two numbers: ";
                cin >> a >> b;

                result = divideNum(a, b);

                if (!isnan(result))
                    cout << "Result = " << result << endl;

                break;

            // 5 Modulus
            case 5: {
                int x, y;

                cout << "Enter two integers: ";
                cin >> x >> y;

                if (y == 0)
                    cout << "Error: Division by zero!\n";
                else
                    cout << "Result = " << x % y << endl;

                break;
            }

            // 6 Power
            case 6:
                cout << "Enter base and exponent: ";
                cin >> a >> b;

                result = pow(a, b);

                cout << "Result = " << result << endl;
                break;

            // 7 Square
            case 7:
                cout << "Enter number: ";
                cin >> a;

                cout << "Square = " << a * a << endl;
                break;

            // 8 Cube
            case 8:
                cout << "Enter number: ";
                cin >> a;

                cout << "Cube = " << a * a * a << endl;
                break;

            // 9 Square Root
            case 9:
                cout << "Enter number: ";
                cin >> a;

                if (a < 0)
                    cout << "Error: Negative number!\n";
                else
                    cout << "Square Root = " << sqrt(a) << endl;

                break;

            // 10 Factorial
            case 10: {
                int n;

                cout << "Enter a positive integer: ";
                cin >> n;

                if (n < 0)
                    cout << "Invalid number!\n";
                else
                    cout << "Factorial = " << factorial(n) << endl;

                break;
            }

            // 11 Absolute
            case 11:
                cout << "Enter number: ";
                cin >> a;

                cout << "Absolute Value = " << fabs(a) << endl;
                break;

            // 12 Sin
            case 12:
                cout << "Enter angle in degrees: ";
                cin >> a;

                result = sin(a * M_PI / 180);

                cout << "Sin = " << result << endl;
                break;

            // 13 Cos
            case 13:
                cout << "Enter angle in degrees: ";
                cin >> a;

                result = cos(a * M_PI / 180);

                cout << "Cos = " << result << endl;
                break;

            // 14 Tan
            case 14:
                cout << "Enter angle in degrees: ";
                cin >> a;

                result = tan(a * M_PI / 180);

                cout << "Tan = " << result << endl;
                break;

            // 15 Log10
            case 15:
                cout << "Enter number: ";
                cin >> a;

                if (a <= 0)
                    cout << "Invalid input!\n";
                else
                    cout << "Log10 = " << log10(a) << endl;

                break;

            // 16 Natural Log
            case 16:
                cout << "Enter number: ";
                cin >> a;

                if (a <= 0)
                    cout << "Invalid input!\n";
                else
                    cout << "ln = " << log(a) << endl;

                break;

            // 17 Exponential
            case 17:
                cout << "Enter x: ";
                cin >> a;

                cout << "e^x = " << exp(a) << endl;
                break;

            // 18 Floor
            case 18:
                cout << "Enter number: ";
                cin >> a;

                cout << "Floor = " << floor(a) << endl;
                break;

            // 19 Ceiling
            case 19:
                cout << "Enter number: ";
                cin >> a;

                cout << "Ceiling = " << ceil(a) << endl;
                break;

            // 20 Percentage
            case 20:
                cout << "Enter number and percentage: ";
                cin >> a >> b;

                result = (a * b) / 100;

                cout << b << "% of " << a
                     << " = " << result << endl;
                break;

            // 21 Average
            case 21: {
                int n;
                double sum = 0, num;

                cout << "How many numbers? ";
                cin >> n;

                for (int i = 1; i <= n; i++) {
                    cout << "Enter number " << i << ": ";
                    cin >> num;
                    sum += num;
                }

                cout << "Average = " << sum / n << endl;

                break;
            }

            // 22 Percentage Increase
            case 22:
                cout << "Enter original and new value: ";
                cin >> a >> b;

                result = ((b - a) / a) * 100;

                cout << "Percentage Increase = "
                     << result << "%\n";
                break;

            // 23 Percentage Decrease
            case 23:
                cout << "Enter original and new value: ";
                cin >> a >> b;

                result = ((a - b) / a) * 100;

                cout << "Percentage Decrease = "
                     << result << "%\n";
                break;

            // 24 Quadratic Equation
            case 24: {
                double A, B, C, D, x1, x2;

                cout << "Equation: Ax^2 + Bx + C = 0\n";

                cout << "Enter A, B and C: ";
                cin >> A >> B >> C;

                D = B * B - 4 * A * C;

                if (D > 0) {

                    x1 = (-B + sqrt(D)) / (2 * A);
                    x2 = (-B - sqrt(D)) / (2 * A);

                    cout << "Root 1 = " << x1 << endl;
                    cout << "Root 2 = " << x2 << endl;

                } else if (D == 0) {

                    x1 = -B / (2 * A);

                    cout << "Both roots = " << x1 << endl;

                } else {

                    cout << "No real roots.\n";
                }

                break;
            }

            // 25 GST
            case 25:
                cout << "Enter price and GST percentage: ";
                cin >> a >> b;

                result = a * b / 100;

                cout << "GST = " << result << endl;
                cout << "Final Price = " << a + result << endl;

                break;

            // 26 Simple Interest
            case 26: {
                double principal, rate, time;

                cout << "Enter Principal, Rate and Time: ";
                cin >> principal >> rate >> time;

                result = (principal * rate * time) / 100;

                cout << "Simple Interest = "
                     << result << endl;

                cout << "Total Amount = "
                     << principal + result << endl;

                break;
            }

            // 27 Compound Interest
            case 27: {
                double principal, rate, time;

                cout << "Enter Principal, Rate and Time: ";
                cin >> principal >> rate >> time;

                result = principal *
                         pow((1 + rate / 100), time);

                cout << "Final Amount = "
                     << result << endl;

                cout << "Compound Interest = "
                     << result - principal << endl;

                break;
            }

            // 28 Celsius -> Fahrenheit
            case 28:
                cout << "Enter Celsius: ";
                cin >> a;

                result = (a * 9 / 5) + 32;

                cout << "Fahrenheit = "
                     << result << endl;

                break;

            // 29 Fahrenheit -> Celsius
            case 29:
                cout << "Enter Fahrenheit: ";
                cin >> a;

                result = (a - 32) * 5 / 9;

                cout << "Celsius = "
                     << result << endl;

                break;

            // 30 Decimal -> Binary
            case 30: {
                int n;

                cout << "Enter decimal number: ";
                cin >> n;

                if (n < 0)
                    cout << "Enter positive number!\n";
                else
                    cout << "Binary = "
                         << decimalToBinary(n) << endl;

                break;
            }

            // 31 Binary -> Decimal
            case 31: {
                string binary;

                cout << "Enter binary number: ";
                cin >> binary;

                int decimal = binaryToDecimal(binary);

                if (decimal == -1)
                    cout << "Invalid binary number!\n";
                else
                    cout << "Decimal = "
                         << decimal << endl;

                break;
            }

            // 32 History
            case 32:

                if (history.empty()) {
                    cout << "No calculation history.\n";
                } else {

                    cout << "\n===== HISTORY =====\n";

                    for (int i = 0; i < history.size(); i++)
                        cout << i + 1 << ". "
                             << history[i] << endl;
                }

                break;

            // 33 Clear History
            case 33:

                history.clear();

                cout << "History cleared successfully.\n";

                break;

            // 34 Exit
            case 34:

                cout << "\nThank you for using the calculator!\n";

                break;

            default:

                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 34);

    return 0;
}
