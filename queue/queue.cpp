// implementation of queue

#include<iostream>

using namespace std;

#define MAX 10 //maximum size of the queue

class queue
{
  int rear, front;
  int array[MAX];

public:
  queue()
  {
    rear = -1;
    front = -1;
  }

  void enqueue(int element)
  {
    if (rear == MAX - 1)
      cout<<"\nqueue overflow\n"; //cannot insert anymore elements
    else
    {
      if(front==-1)
      {
        array[++front]=element;
        array[++rear]=element;
      }
      else
      {
        array[++rear] = element;
        cout<<"Insertion successful\n";
      }
    }
  }

  void dequeue()
  {
    if (front == -1)
      cout<<"queue underflow\n"; //no elements to delete
    else
    {
      cout<<"Deleted successfully : "<<array[front]<<"\n";
      if(front==rear)
      {
        front = -1;
        rear = -1;
      }
      else
        ++front;
    }
  }

  void show_queue()
  {
    if(front==rear)
    {
      if(front==-1)
        cout<<"Queue empty\n";
      else
        cout<<array[front]<<"\n";
    }
    else
    {
      cout<<"\n";
      for(int i=front;i<=rear;i++)
        cout<<array[i]<<" ";
    }
  }
};

int main()
{
  queue q;
  int choice;
  while(1)
  {
    cout<<"Menu:\n1.Insert\n2.Delete\n3.Show queue\n4.Quit\n";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"\nEnter the element to be inserted ";
              int element;
              cin>>element;
              q.enqueue(element);
              break;
      case 2: q.dequeue();
              break;
      case 3: q.show_queue();
              break;
      case 4: cout<<"\nThank you";
              return 0;
              break;
    }
  }
}
