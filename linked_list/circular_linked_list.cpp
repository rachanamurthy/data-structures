#include<iostream>
#include<process.h>

using namespace std;
//class is created for the circular linked list
class Circular_Linked
{
	//structure node is created
	struct node
	{
		int info;
		struct node *link;
	};
	struct node *last;
	typedef struct node *NODE;
	public:
		//Constructor is defined
		Circular_Linked()
		{
			last=NULL;
		}
		void create_list(int);
		void addatbeg(int);
		void addafter(int,int);
		void del();
		void display();
};
//A circular list created in this function
void Circular_Linked::create_list(int num)
{
	NODE q,tmp;
	//New node is created
	tmp = (NODE)new(struct node);
	tmp->info = num;
	if (last == NULL)
	{
		last = tmp;
		tmp->link = last;
	}
	else
	{
		tmp->link = last->link; /*added at the end of list*/
		last->link = tmp;
		last = tmp;
	}
}/*End of create_list()*/
//This function will add new node at the beginning
void Circular_Linked::addatbeg(int num)
{
	NODE tmp;
	tmp = (NODE)new(struct node);
	tmp->info = num;
	tmp->link = last->link;
	last->link = tmp;
}/*End of addatbeg()*/
//Function to add new node at any position of the circular list
void Circular_Linked::addafter(int num,int pos)
{
	NODE tmp,q;
	int i;
	q = last->link;
	//finding the position to insert a new node
	for(i=0; i < pos-1; i++)
	{
		q = q->link;
		if (q == last->link)
		{
			cout<<"There are less than "<<pos<<" elements\n";
			return;
		}
	}/*End of for*/
	//creating the new node
	tmp = (NODE)new(struct node);
	tmp->link = q->link;
	tmp->info = num;
	q->link = tmp;
	if(q==last) /*Element inserted at the end*/
	last=tmp;
}/*End of addafter()*/
//Function to delete a node from the circular linked list
void Circular_Linked::del()
{
	int num;
	if(last == NULL)
	{
		cout<<"\nList underflow\n";
		return;
	}
	cout<<"\nEnter the number for deletion:";
	cin>>num;
	NODE tmp,q;
	if( last->link == last && last->info == num) /*Only one element*/
	{
		tmp = last;
		last = NULL;
		//deleting the node
		delete(tmp);
		return;
	}
	q = last->link;
	if(q->info == num)
	{
		tmp = q;
		last->link = q->link;
		//deleting the node
		delete(tmp);
		return;
	}
	while(q->link != last)
	{
		if(q->link->info == num) /*Element deleted in between*/
		{
			tmp = q->link;
			q->link = tmp->link;
			delete(tmp);
			cout<<"\n"<<num<<" deleted\n";
			return;
		}
		q = q->link;
	}/*End of while*/
	if(q->link->info == num) /*Last element deleted q->link=last*/
	{
		tmp = q->link;
		q->link = last->link;
		delete(tmp);
		last = q;
		return;
	}
	cout<<"\nElement "<<num<<" not found\n";
}/*End of del()*/
//Function to display all the nodes in the circular linked list
void Circular_Linked::display()
{
	NODE q;
	if(last == NULL)
	{
		cout<<"\nList is empty\n";
		return;
	}
	q = last->link;
	cout<<"\nList is: ";
	while(q != last)
	{
		cout<<q->info<<" ";
		q = q->link;
	}
	cout<<last->info<<"\n";
}/*End of display()*/

int main()
{
	int choice,n,m,po,i;
	Circular_Linked co;//Object is created for the class
	while(1)
	{
		//Menu options
		cout<<"\n1.Create List\n";
		cout<<"2.Add at begining\n";
		cout<<"3.Add after \n";
		cout<<"4.Delete\n";
		cout<<"5.Display\n";
		cout<<"6.Quit\n";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nHow many nodes you want: ";
				cin>>n;
				for(i=0; i < n;i++)
				{
					cout<<"\nEnter the element: ";
					cin>>m;
					co.create_list(m);
				}
				break;
			case 2:
				cout<<"\nEnter the element: ";
				cin>>m;
				co.addatbeg(m);
				break;
			case 3:
				cout<<"\nEnter the element: ";
				cin>>m;
				cout<<"\nEnter the position after which this element is inserted: ";
				cin>>po;
				co.addafter(m,po);
				break;
			case 4:
				co.del();
				break;
			case 5:
				co.display();
			break;
			case 6:
				exit(0);
			default:
			cout<<"\nWrong choice\n";
		}/*End of switch*/
	}/*End of while*/
}/*End of main()*/
