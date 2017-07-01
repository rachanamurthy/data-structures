//stack data structure

#include<iostream>

using namespace std;

#define MAX 10

class Stack
{
    int top; //index of the top element
    int a[MAX]; //MAX- maximum size of the stack

    public:

    Stack()
    {
        top = -1;
    }

    void push(int element)
    {
        if (top >= MAX)
            cout<<"Stack Overflow "; //stack is full and hence cannot insert an element
        else
        {
            top++;
            a[top] = element;
            cout<<"Push Operation Successful ";
        }
    }

    int pop()
    {
        if (top == -1)
        {
            cout<<"Stack Underflow "; //No element present in stack to pop
            return -1;
        }
        else
        {
            int popped_element = a[top];
            top--;
            cout<<"Pop operation successful ";
            return popped_element;
        }
    }

    int show_top()
    {
        cout<<"The top element is "<<a[top];
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    void show_stack()
    {
        cout<<"The content of the stack is as follows: ";
        for(int i = 0; i<=top; i++)
            cout<<a[i]<<"  ";
    }

};

int main()
{
    Stack s;
    int operation;
    char choice = 'y';
    while (choice == 'y')
    {
      cout<<"Enter your choice:\n1.Push\n2.Pop\n3.Show Top\n4.isEmpty\n5.Show Stack\n";
      cin>>operation;

      switch(operation)
      {
          case 1: int element;
                  cout<<"Enter the element to be pushed ";
                  cin>>element;
                  s.push(element);
                  break;

          case 2: s.pop();
                  break;

          case 3: s.show_top();
                  break;

          case 4: s.isEmpty();
                  break;

          case 5: s.show_stack();
                  break;
      }

      cout<<"Press 'y' to continue and 'n' to quit ";
      cin>>choice;
    }

}
