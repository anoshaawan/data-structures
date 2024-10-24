#include<iostream>
using namespace std;

class node
{
	public :
		int data;
		node *next;
		
	node()
	{
		this->data=0;
		this->next=nullptr;
	}	
};

class doubly
{
	public :
		node *head;
		
	doubly()
	{
		head=nullptr;
	}
	
	void traverse()
	{
		node *k;
		k=head;
		
		do{
			cout<<k->data<<endl;
			k=k->next;
		}
		while( k!=head);
		
		cout<<endl;
	}	

    void addstart( int data )
    {
		node *newNode=new node;
		newNode->data=data;
	
		if( head==nullptr )
		{
			newNode->next=newNode;
			head=newNode;
		}
		else
		{
			node *k=head;
			while(k->next!=head)
			{
				k=k->next;
			}
			k->next=newNode;
			newNode->next=head;
			head=newNode;
		}
	}
	
	void delstart()
{
	if (head==NULL)
	{
		cout<<"list is empty"<<endl;
	}
	else
	{
   node *first = head;
   node *last = head;
   while(last->next!=head)
   {
   	last=last->next;
   }
   last->next=first->next;
   head=first->next;
	delete first; 
}
}

void delmid(int pos)
{
	node *temp=head;
	node *pr;
	while(temp->data!=pos)
	{
		pr=temp;
		temp=temp->next;
	}
	pr->next=temp->next;
	delete temp;
	
}

void delend()
{
	node *temp=head;
	node *p;
	while(temp->next!=head)
	{
		p=temp;
		temp=temp->next;
	}
	p->next=head;
	delete temp;
}
};

int main()
{
	doubly d;
	cout<<"traverse"<<endl;
	d.addstart(40);
	d.addstart(30);
	d.addstart(20);
	d.addstart(10);
	d.addstart(5);
	d.traverse();
	cout<<"del at start"<<endl;
	d.delstart();
	d.traverse();
	cout<<"del at mid"<<endl;
	d.delmid(20);
	d.traverse();
	cout<<"del at end"<<endl;
	d.delend();
	d.traverse();
	return 0;
	
	
	
	
	
	
	
	
	
}