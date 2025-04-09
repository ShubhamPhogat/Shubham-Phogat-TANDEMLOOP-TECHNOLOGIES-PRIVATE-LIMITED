#include <bits/stdc++.h>
using namespace std;

class Calculator {
    static map<char, int> priority;

    vector<string> infixToPostfix(const string& s) {
        vector<string> postfix;
        stack<char> operators;
        string expr = '(' + s + ')';
        int n = expr.size();

        try {
            for (int i = 0; i < n; ++i) {
                char ch = expr[i];

                if (isspace(ch)) continue;

                if (isdigit(ch) || ch == '.') {
                    string number;
                    while (i < n && (isdigit(expr[i]) || expr[i] == '.')) {
                        number.push_back(expr[i]);
                        ++i;
                    }
                    --i; // step back
                    postfix.push_back(number);
                } else if (ch == '(') {
                    operators.push(ch);
                } else if (ch == ')') {
                    while (!operators.empty() && operators.top() != '(') {
                        postfix.push_back(string(1, operators.top()));
                        operators.pop();
                    }
                    if (!operators.empty()) operators.pop(); // pop '('
                    else throw runtime_error("Mismatched parentheses");
                } else if (priority.count(ch)) {
                    while (!operators.empty() && operators.top() != '(' &&
                           priority[operators.top()] >= priority[ch]) {
                        postfix.push_back(string(1, operators.top()));
                        operators.pop();
                    }
                    operators.push(ch);
                } else {
                    throw runtime_error("Invalid character in expression");
                }
            }
            return postfix;
        } catch (const exception &e) {
            cout << "Error (Postfix Conversion): " << e.what() << endl;
            return {};
        }
    }

public:
    double eval(const string& s) {
        stack<double> compute;
        try {
            vector<string> postfix = infixToPostfix(s);
            if (postfix.empty()) throw runtime_error("Invalid expression");

            for (const string& token : postfix) {
                if (token == "+" || token == "-" || token == "*" || token == "/") {
                    if (compute.size() < 2) throw runtime_error("Not enough operands");
                    double b = compute.top(); compute.pop();
                    double a = compute.top(); compute.pop();

                    if (token == "+") compute.push(a + b);
                    else if (token == "-") compute.push(a - b);
                    else if (token == "*") compute.push(a * b);
                    else {
                        if (b == 0) throw runtime_error("Division by zero");
                        compute.push(a / b);
                    }
                } else {
                    compute.push(stod(token));
                }
            }

            if (compute.size() != 1) throw runtime_error("Invalid computation");
            return compute.top();
        } catch (const exception &e) {
            cout << "Error (Evaluation): " << e.what() << endl;
            return 0;
        }
    }
};

map<char, int> Calculator::priority = {
    {'+', 0},
    {'-', 0},
    {'*', 1},
    {'/', 1}
};

int main() {
    Calculator calc;
    string input;
    cout << "Simple Calculator (supports +, -, *, /, decimals)\n";
    cout << "Enter 0 to exit.\n\n";

    while (true) {
        cout << "Enter expression: ";
        getline(cin, input);

        if (input == "0") break;
        double result = calc.eval(input);
        cout << "Result: " << result << "\n\n";
    }

    cout << "Goodbye!\n";
    return 0;
}
