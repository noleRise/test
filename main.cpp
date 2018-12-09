#include <iostream>
#include "Stack.h"
#include <string>
#include <math.h>
using namespace std;

bool valid = true;
int rank(char);
void processAnOperator(Stack<double>& dataStack, Stack<char>& operatorStack);
void calculate(const string& s, double& result);

int main()
{
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);
    double result;
    calculate(expression, result);
    if(fpclassify(result) == FP_INFINITE || fpclassify(result) == FP_NAN)
        cout << "error!" << endl;
    else if(valid)
        cout << expression << "=" << result << endl;

    return 0;
}

int rank(char ch)
{
    int flag;
    if(ch == '#')
        flag = 1;
    else if(ch == ')')
        flag = 2;
    else if(ch == '|')
        flag = 3;
    else if(ch == '&')
        flag = 4;
    else if(ch == '+' || ch == '-')
        flag = 5;
    else if(ch == '*' || ch == '/')
        flag = 6;
    else if(ch == '!')
        flag = 7;
    else if(ch == '(')
        flag = 8;
    else if(ch == '.')
        flag = 9;
    return flag;
}

void processAnOperator(Stack<double>& dataStack, Stack<char>& operatorStack)
{
    char op = operatorStack.peek();
    operatorStack.pop();
    double op1 = dataStack.peek();
    dataStack.pop();
    if(op == '!'){
        dataStack.push(!op1);
        return ;
    }
    double op2 = dataStack.peek();
    dataStack.pop();

    if (op == '+')
        dataStack.push(op2 + op1);
    else if (op == '-')
        dataStack.push(op2 - op1);
    else if (op == '*')
        dataStack.push(op2 * op1);
    else if (op == '/')
        dataStack.push(op2 / op1);
    else if (op == '.'){
        while(op1 >= 1)
            op1 /= 10;
        dataStack.push(op1 + op2);
    }
    else if (op == '&')
        dataStack.push(op2 && op1);
    else if (op == '|')
        dataStack.push(op2 || op1);
}

void calculate(const string& s, double& result)
{
    Stack<double> s1;
    Stack<char> s2;
    s2.push('#');

    for (unsigned i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            double a = s[i++] - '0';
            for ( ; s[i] >= '0' && s[i] <= '9'; i++)
                a = a * 10 + s[i] - '0';
            i--;
            s1.push(a);
        }

        else if (s[i] != ')' && (rank(s[i]) > rank(s2.peek()) || s2.peek() == '(')){
            s2.push(s[i]);
            if(s[i] == '&' || s[i] == '|')
                i++;
        }

        else if (s[i] == ')'){
            while(s2.peek() != '('){
                if(s2.peek() != '#')
                    processAnOperator(s1, s2);
                else{
                    cout << "left is less than right" << endl;
                    valid = false;
                    return;
                }
            }
            s2.pop();
        }

        else if (rank(s[i]) <= rank(s2.peek())){
            processAnOperator(s1, s2);
            s2.push(s[i]);
        }
    }

    while (!s2.empty()){
        if (s2.peek() == '#')
            s2.pop();
        else if(s2.peek() == '('){
            cout << "left is more than right" << endl;
            valid = false;
            return;
        }
        else
            processAnOperator(s1, s2);
    }

    result = s1.peek();
    s1.pop();
    return;
}
