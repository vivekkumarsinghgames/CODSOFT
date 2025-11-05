#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;

    cout << "Simple Calculator\n";
    cout << "-----------------\n";

    // Get user input
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    // Perform the chosen operation
    switch (op) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else {
                cout << "Error: Division by zero is not allowed!" << endl;
                return 1;
            }
            cout << "Result: " << result << endl;
            break;
        default:
            cout << "Error: Invalid operator!" << endl;
            return 1;
    }

    return 0;
}
