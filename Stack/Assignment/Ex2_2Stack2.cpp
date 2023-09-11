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
        bool empty();
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

bool MyStack :: empty(){
    if(topVal==-1){
        return true;
    }else{
        return false;
    }
}

class InfixToPostfix {
private:
    string operators;
    string output;

    int getPriority(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        if (op == '^')
            return 3;
        return -1;
    }

public:
    InfixToPostfix() {
        operators = "+-*/^";
    }

    string infixToPostfix(const string& infixExpression) {
        MyStack stk;

        for (char c : infixExpression) {
            if (isalnum(c)) { //To Check if the character is alphanumeric
                output += c;
            } else if (c == '(') {
                stk.push(c);
            } else if (c == ')') {
                while (!stk.empty() && stk.top() != '(') {
                    output += stk.top();
                    stk.pop();
                }
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                }
            } else if (operators.find(c) != string::npos) { //checks if the character index within the string is not equal to 'not found'.
                while (!stk.empty() && getPriority(c) <= getPriority(stk.top())) {
                    output += stk.top();
                    stk.pop();
                }
                stk.push(c);
            }
        }

        while (!stk.empty()) {
            output += stk.top();
            stk.pop();
        }

        return output;
    }
};

int main() {
    string infixExpression1 = "a*b+c/d";
    string infixExpression2 = "a+b*c-d/e^f";
    string infixExpression3 = "(a-b/c)*(a/k-l)";

    InfixToPostfix converter1, converter2, converter3;

    string postfixExpression1 = converter1.infixToPostfix(infixExpression1);
    string postfixExpression2 = converter2.infixToPostfix(infixExpression2);
    string postfixExpression3 = converter3.infixToPostfix(infixExpression3);

    cout << "Infix Expression 1: " << infixExpression1 << endl;
    cout << "Postfix Expression 1: " << postfixExpression1 << endl;
    cout<<endl;
    cout << "Infix Expression 2: " << infixExpression2 << endl;
    cout << "Postfix Expression 2: " << postfixExpression2 << endl;
    cout<<endl;
    cout << "Infix Expression 3: " << infixExpression3 << endl;
    cout << "Postfix Expression 3: " << postfixExpression3 << endl;
    cout<<endl;

    return 0;
}
