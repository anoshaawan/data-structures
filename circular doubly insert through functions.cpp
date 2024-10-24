#include<iostream>
using namespace std;

class node
{
    public:
        node *prev;
        int data;
        node *next;
        
        node()
        {
            this->prev = NULL;
            this->next = NULL;
            this->data = 0;
        }
};

class doublyLinkedList
{
    public:
        node *head;
        
        doublyLinkedList()
        {
            head = 0;
        }
        
        void traverse()
        {
            node *current;
            current = head;
            do
            {
                cout << current->data << " ";
                current = current->next;
            } while (current != head);
            cout << endl;
        }
        
        void addAtBeginning(int data)
        {
            node *newNode = new node;
            newNode->data = data;
            if (head == NULL)
            {
                newNode->next = newNode;
                newNode->prev = newNode;
                head = newNode;
            }
            else
            {
                node *temp;
                temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = head;
                newNode->prev = temp;
                head->prev = newNode;
                head = newNode;
            }
        }
        
        void addAtEnd(int val)
        {
            node *newNode = new node;
            newNode->data = val;
            if (head == NULL)
            {
                newNode->prev = newNode;
                newNode->next = newNode;
                head = newNode;
            }
            else
            {
                node *lastNode;
                lastNode = head;
                while (lastNode->next != head)
                {
                    lastNode = lastNode->next;
                }
                lastNode->next = newNode;
                newNode->next = head;
                newNode->prev = lastNode;
                head->prev = newNode;
            }
        }
        
        void addInMiddle(int positionValue, int val)
        {
            node *newNode = new node;
            newNode->data = val;
            if (head == NULL)
            {
                head = newNode;
            }
            else
            {
                node *currentNode = head;
                while (currentNode->data != positionValue)
                {
                    currentNode = currentNode->next;
                }
                newNode->prev = currentNode;
                newNode->next = currentNode->next;
                currentNode->next->prev = newNode;
                currentNode->next = newNode;
            }
        }
        
       
};

int main()
{
    doublyLinkedList list1;
    list1.addAtBeginning(5);
    list1.addAtBeginning(4);
    list1.addAtBeginning(3);
    list1.addAtBeginning(2);
    list1.addAtBeginning(1);
    
    cout << "traversal" << endl;
    list1.traverse();
    
    list1.addAtEnd(6);
     list1.addAtEnd(7);
    list1.traverse();
    list1.addInMiddle(3, 10);
     list1.traverse();
    list1.addAtBeginning(0);
     list1.traverse();
    
    
  
    return 0;
}
