#include<iostream>
using namespace std;
class node
{
	public:
		int info;
		node *next;
	node()
	{
		info=0;
		next=NULL;
	}
	node(int x,node *l=NULL)
	{
		info=x;
		next=l;
	}
};

class list
{
	private:
		node *head,*tail;
	public:
		list()
		{
			head=NULL;
			tail=NULL;
		}
		int isempty()
		{
			if(head==NULL)
			return 1;
			else
			return 0;
		}
		void addtohead(int e)
		{
			if(isempty())
			{
				head=new node(e);
				tail=head;
			}
			else
			{
				node *temp=new node(e,head);
				head=temp;
			}
		}
		void display()
		{
			if(!isempty())
			{
				node *temp=head;
				while(temp!=NULL)
				{
					cout<<temp->info<<"\t";
					temp=temp->next;
				}
				cout<<endl;
			}
			else
			cout<<"It is empty"<<endl;
		}
		void addtotail(int e)
		{
			if(isempty())
                        {
                                head=new node(e);
                                tail=head;
                        }
                        else
                        {
                               node *temp=new node(e);
                               tail->next=temp;
			       tail=temp;
                        }

		}
		void deletehead()
		{
			if(!isempty())
			{
				if(head==tail)
				{
					head=NULL;
					tail=NULL;
				}
				else
				head=head->next;
			}
			else
			cout<<"There is no node"<<endl;
		}
		void deletetail()
		{
			if(!isempty())
			{
				if(head==tail)
				{
					head=NULL;
					tail=NULL;
				}
				else
				{
					node *temp=head;
					while(temp->next!=tail)
					{
						temp=temp->next;
					}
					temp->next=NULL;
					tail=temp;
				}
			}
		}
		void insert_after(int ele1,int ele2)
		{
				if(head==NULL)
				head=new node(ele2);
				else
				{
					node *temp=head;
					while((temp->info!=ele1)&&(temp!=NULL))
					temp=temp->next;
					if(temp==NULL)
					{
						cout<<"Element not found"<<endl;
						return;
					}
					else
					{
						node *t=new node(ele2);
						t->next=temp->next;
						temp->next=t;
						if(temp==tail)
						tail=t;
					}
				}
		}
		void insert_before(int ele1,int ele2)
		{
			        if(head==NULL)
                                head=new node(ele2);
				else
                                {
                                        node *temp=head;
					while((temp->next->info!=ele1)&&(temp->next!=NULL))
                                        {
						temp=temp->next;

					}
                                        if(temp->next==NULL)
                                        {
                                               cout<<"Element not found"<<endl;
                                        }
                                        else
                                        {
                                                node *t=new node(ele2);
                                                t->next=temp->next;
                                                temp->next=t;
                                        }
                                 }

		}
		void search(int ele)
		{
			int k=0,j=0;
			node *temp=head;
			while(temp!=NULL)
			{
				if(temp->info==ele)
				{
					j++;
					k=1;
					break;
				}
				else
				{
					j++;
					temp=temp->next;
				}

			}
			if(k==1)
			cout<<"Element found in "<<j<<"node"<<endl;
			else
			cout<<"Element not found"<<endl;
		}
		void count()
		{
			int k=0;
			node *temp;
			for(temp=head;temp!=NULL;temp=temp->next)
			k++;
			cout<<"Number of nodes = "<<k<<endl;
		}
};
int main()
{
	list *l=new list();
	int z=1,k,x,y;
	cout<<"\n-----------List of SLL operations------------"<<endl;
	cout<<"1.Add to head"<<"\n"<<"2.Add to tail"<<"\n"<<"3.Isempty"<<"\n"<<"4.Delete head"<<"\n"<<"5.Delete tail"<<"\n"<<"6.Insert_after"<<"\n"<<"7.Insert_before"<<"\n"<<"8.Search"<<"\n"<<"9.Count the nodes"<<"\n"<<"10.Display"<<endl;
	cout<<"---------------------------------------------"<<endl;
	while(z)
	{
		cout<<"Enter the option: ";
		cin>>k;
		switch(k)
		{
			case 1:
				cout<<"Enter the element to be inserted: ";
				cin>>x;
				l->addtohead(x);
				break;
			case 2:
				cout<<"Enter the element to be inserted: ";
				cin>>x;
				l->addtotail(x);
				break;
			case 3:
				if(l->isempty())
				cout<<"List is empty"<<endl;
				else
				cout<<"List is not empty"<<endl;
				break;
			case 4:
				l->deletehead();
				break;
			case 5:
				l->deletetail();
				break;
			case 6:
				cout<<"Enter the element to be inserted and also after which element:  ";
				cin>>x>>y;
				l->insert_after(y,x);
				break;
			case 7:
				cout<<"Enter the element to be inserted and also before which element: ";
                                cin>>x>>y;
                                l->insert_before(y,x);
                                break;
			case 8:
				cout<<"Enter the element to search in the list: ";
				cin>>y;
				l->search(y);
				break;
			case 9:
				l->count();
				break;
			case 10:
				l->display();
				break;
		}
		cout<<"If you want to continue press 1 else 0 :";
		cin>>z;
		cout<<endl;
	}
	return 0;
}