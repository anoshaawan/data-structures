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
	
	void addmid( int data , int pos )
	{
		node *temp;
		temp=new node ;
		temp->data=data;
		temp->next=nullptr;
	
		if( head==nullptr )
		{
			head=temp;
		}
		else
		{
			node *kkk=head;
			while( kkk->data!=pos )
			{
				kkk=kkk->next;
			}
			temp->pre=kkk;
			temp->next=kkk->next;
			kkk->next->pre=temp;
			kkk->next=temp;
		}
	}

	void addend( int data )
	{
		node *temp;
		temp=new node ;
		temp->data=data;
		temp->next=nullptr;
	
		if( head==nullptr )
		{
			head=temp;
		}
		else
		{
			node *kk=head;
			while( kk->next!=nullptr )
			{
				kk=kk->next;
			}
			temp->pre=kk;
			kk->next=temp;
		}
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


















