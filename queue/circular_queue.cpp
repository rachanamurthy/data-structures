#include<conio.h>
#include<process.h>
#include<iostream>
#define MAX 50
//A class is created for the circular queue
using namespace std;

class circular_queue
{
	int cqueue_arr[MAX];
	int front,rear;
	public:
		//a constructor is created to initialize the variables
		circular_queue()
		{
			front = -1;
			rear = -1;
		}
		//public function declarations
		void insert();
		void del();
		void display();
};
//Function to insert an element to the circular queue
void circular_queue::insert()
{
	int added_item;
	//Checking for overflow condition
	if ((front == 0 && rear == MAX-1) || (front == rear +1))
	{
		cout<<"\nQueue Overflow \n";
		getch();
		return;
	}
	if (front == -1) /*If queue is empty */
	{
		front = 0;
		rear = 0;
	}
	else if (rear == MAX-1)/*rear is at last position of queue */
		rear = 0;
	else
		rear = rear + 1;
	cout<<"\nInput the element for insertion in queue:";
	cin>>added_item;
	cqueue_arr[rear] = added_item;
}/*End of insert()*/
//This function will delete an element from the queue
void circular_queue::del()
{
	//Checking for queue underflow
	if (front == -1)
	{
		cout<<"\nQueue Underflow\n";
		return;
	}
	cout<<"\nElement deleted from queue is:"<<cqueue_arr[front]<<"\n";
	if (front == rear) /* queue has only one element */
	{
		front = -1;
		rear = -1;
	}
	else if(front == MAX-1)
		front = 0;
	else
		front = front + 1;
}/*End of del()*/
//Function to display the elements in the queue
void circular_queue::display()
{
	int front_pos = front,rear_pos = rear;
	//Checking whether the circular queue is empty or not
	if (front == -1)
	{
		cout<<"\nQueue is empty\n";
		return;
	}
	//Displaying the queue elements
	cout<<"\nQueue elements:\n";
	if(front_pos <= rear_pos)
	{
		while(front_pos <= rear_pos)
		{
			cout<<cqueue_arr[front_pos]<<" ";
			front_pos++;
		}
	}
	else
	{
		while(front_pos <= MAX-1)
		{
			cout<<cqueue_arr[front_pos]<<" ";
			front_pos++;
		}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{
			cout<<cqueue_arr[front_pos]<<" ";
			front_pos++;
		}
	}/*End of else*/
	cout<<"\n";
}/*End of display() */

int main()
{
	int choice;
	//Creating the objects for the class
	circular_queue co;
	while(1)
	{
		//Menu options
		cout <<"\n1.Insert\n";
		cout <<"2.Delete\n";
		cout <<"3.Display\n";
		cout <<"4.Quit\n";
		cout <<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				co.insert();
				break;
			case 2 :
				co.del();
				getch();
				break;
			case 3:
				co.display();
				getch();
				break;
			case 4:
				exit(1);
			default:
				cout<<"\nWrong choice\n";
				getch();
		}/*End of switch*/
	}/*End of while*/
}/*End of main()*/
