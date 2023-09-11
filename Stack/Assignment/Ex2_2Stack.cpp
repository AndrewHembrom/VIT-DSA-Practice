#include <iostream>
using namespace std;

#define MAX 100 //max size for stack

class MyStack{
    
    int topVal;

    public:
        int stack[MAX]; //stack array

        MyStack(){ topVal = -1;}
        void push(int data);
        int pop();
        int top();
};

void MyStack :: push(int data){
    if(topVal==MAX-1){
        cout<<"Stack Overflow!"<<endl;
    }
    else{
        topVal++;
        stack[topVal]=data;
    }
}

int MyStack :: pop(){
    int temp;
    if(topVal==-1){
        cout<<"Stack Underflow!";
        return 0;
    }
    else{
        temp = stack[topVal];
        topVal--;
    }
    return temp;
}

int MyStack :: top(){
    return stack[topVal];
}

class EvaluatePostfix {
public:
    int evaluate(string postfix) {
        MyStack operandStack;

        string operand = "";
        for (char c : postfix) {
            if (c == ' ') {
                if (!operand.empty()) {
                    operandStack.push(stoi(operand)); //converting string to integer
                    operand = "";
                }
            } else if (isdigit(c)) {
                operand += c;
            } else if (isOperator(c)) {
                int operand2 = operandStack.top();
                operandStack.pop();
                int operand1 = operandStack.top();
                operandStack.pop();

                int result = performOperation(c, operand1, operand2);
                operandStack.push(result);
            }
        }

        return operandStack.top();
    }

private:
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    int performOperation(char op, int operand1, int operand2) {
        switch (op) {
            case '+':
                return operand1 + operand2;
            case '-':
                return operand1 - operand2;
            case '*':
                return operand1 * operand2;
            case '/':
                return operand1 / operand2;
            case '^':
                return power(operand1, operand2);
            default:
                throw runtime_error("Invalid Expression");
        }
    }

    int power(int base, int exponent) {
        int result = 1;
        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }
        return result;
    }
};

int main() {
    EvaluatePostfix evaluator;

    string postfixExpression1 = "2 3 1 * + 9 -";  // TestCase 1
    string postfixExpression2 = "2 3 4 * + 16 2 3 ^ / -";  // TestCase 2

    int result1, result2;
 
    result1 = evaluator.evaluate(postfixExpression1);
    cout << "TestCase 1 Result: " << result1 << endl;

    result2 = evaluator.evaluate(postfixExpression2);
    cout << "TestCase 2 Result: " << result2 << endl;

    return 0;
}
