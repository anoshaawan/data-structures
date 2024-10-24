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
			node *lastnode = head;
			while(lastnode->next!=head)
			{
				lastnode=lastnode->next;
			}
			lastnode->next=newNode;
			newNode->next=head;
			head=newNode;
		}
	}
	
	void addmid( int data , int pos )
	{
		node *newNode=new node;
		newNode->data=data;
	
			node *kkk=head;
			while( kkk->data!=pos )
			{
				kkk=kkk->next;
			}
			newNode->next=kkk->next;
			kkk->next=newNode;
		}

	void addend( int data )
	{
		node *newNode=new node;
		newNode->data=data;
	
			node *kk=head;
			while( kk->next!=head )
			{
				kk=kk->next;
			}
			kk->next=newNode;
			newNode->next=head;
		}
	
};

int main()
{
	doubly D;
	cout<<"traversing:"<<endl;
	D.addstart(40);
	D.addstart(30);
	D.addstart(20);
	D.addstart(10);
	D.traverse();
	cout<<"insert at start:"<<endl;
	D.addstart(5);
	D.traverse();
    cout<<"insert at mid:"<<endl;
	D.addmid(25,20);
	D.traverse();
	cout<<"insert at end:"<<endl;
	D.addend(50);
	D.traverse();
	return 0;
}


















