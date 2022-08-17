#include <iostream>
#include <stack>

using namespace std;


//implementation of stack without STL
class Stack{
    //properties
    public:
        int *arr;
        int top;
        int size;

    //behavior;
    Stack(int size){
        this->size = size;
        arr=new int[size];
        top =-1;
    }
    void push(int element){
        if(size-top>1){
            top++;
            arr[top] = element;
        }else{
            cout<<"stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{

    Stack s(5);

    s.push(2);
    s.push(7);
    s.push(15);

    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;

    if(s.isEmpty()){
        cout<<"stack empty hai re baba "<<endl;
    }
    else{
        cout<<"stack empty nhi hai re baba "<<endl;
    }

    /*  use of STL
    //creation Of stack
    stack<int> s;

    //push operation
    s.push(3);
    s.push(5);
    s.push(7);
    //pop operation
    s.pop();

    cout<<"top element is "<<s.top()<<endl;

    if(s.empty()){
        cout<<"Stack is empty "<<endl;
    }
    else{
        cout<<"Stack is not empty "<<endl;
    }
    */
    return 0;
}
