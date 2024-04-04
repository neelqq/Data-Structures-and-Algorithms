#include <iostream>
#include <limits.h>
#include <stack>
#define MAX 20

using namespace std;

char stk[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

char peek() {
    return stk[top];
}

char pop() {
    if (isEmpty())
        return -1;

    char ch = stk[top];
    top--;
    return ch;
}

void push(char oper) {
    if (isFull())
        cout << "Stack Full!!!!";
    else {
        top++;
        stk[top] = oper;
    }
}

bool checkIfOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}

void convertInfixToPostfix(char expression[]) {
    int i, j;

    for (i = 0, j = -1; expression[i]; ++i) {
        if (checkIfOperand(expression[i]))
            expression[++j] = expression[i];

        else if (expression[i] == '(')
            push(expression[i]);

        else if (expression[i] == ')') {
            while (!isEmpty() && peek() != '(')
                expression[++j] = pop();
            if (!isEmpty() && peek() != '(')
                return;
            else
                pop();
        } else {
            while (!isEmpty() && precedence(expression[i]) <= precedence(peek()))
                expression[++j] = pop();
            push(expression[i]);
        }
    }

    while (!isEmpty())
        expression[++j] = pop();

    expression[++j] = '\0';
    cout << expression;
}

int main() {
    char expression[] = "((5*(6+7))-8)";
    convertInfixToPostfix(expression);
    return 0;
}