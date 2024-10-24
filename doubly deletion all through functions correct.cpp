#include<iostream>
using namespace std;

class node
{
	public :
		node *pre;
		int data;
		node *next;
		
	node()
	{
		this->pre=nullptr;
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
		
		while( k!=nullptr)
		{
			cout<<k->data<<endl;
			k=k->next;
		}
		
		cout<<endl;
	}	

    void addstart( int data )
    {
		node *temp=new node;
		temp->data=data;
	
		if( head==nullptr )
		{
			temp->next=nullptr;
			head=temp;
		}
		else
		{
			temp->next=head;
			temp->pre=nullptr;
			head->pre=temp;
			head=temp;
		}
	}
	
	void delstart()
{
   
    
    node *temp = head; 
    head = head->next; 
	head->pre = nullptr; 
	delete temp; 
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
	temp->next->pre=pr;
	delete temp;
	
}

void delend()
{
	node *temp=head;
	node *p;
	while(temp->next!=NULL)
	{
		p=temp;
		temp=temp->next;
	}
	p->next=NULL;
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