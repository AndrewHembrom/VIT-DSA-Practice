#include <iostream>
using namespace std;

#define MAX 100 //max size for stack

class MyStack{
    
    int top;

    public:
        int stack[MAX]; //stack array

        MyStack(){ top = -1;}
        void push(int data);
        int pop();
        void isEmpty();
        void display();
};

void MyStack :: push(int data){
    if(top==MAX-1){
        cout<<"Stack Overflow!"<<endl;
    }
    else{
        top++;
        stack[top]=data;
    }
}

int MyStack :: pop(){
    int temp;
    if(top==-1){
        cout<<"Stack Underflow!";
        return 0;
    }
    else{
        temp = stack[top];
        top--;
    }
    return temp;
}

void MyStack :: isEmpty(){
    if(top==-1){
        cout<<"Stack is Empty"<<endl;
    }
    else{
        cout<<"Stack is not Empty"<<endl;
    }
}

void MyStack::display()
{
 	if(top==-1)
 	    cout<<"stack empty\n";
 	else
 	{
 	    for(int i=top; i>=0; i--)
 	 	{
 	 		cout<<"Elements are: ";
 	 		cout<<stack[i];
 	 		cout<<endl;
	    }
	}cout<<endl;
}

int main(){
    MyStack stack;
    cout<<"The Stack Push"<<endl;
    stack.push(2);
    stack.push(4);
    stack.push(6);
    stack.push(8);
    stack.display();
    stack.pop();
    stack.display();
    stack.isEmpty();
    stack.display();
}
