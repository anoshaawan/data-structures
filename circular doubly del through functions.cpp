#include<iostream>
using namespace std;

class node
{
    public:
        node *prevNode;
        int value;
        node *nextNode;
        
        node()
        {
            this->prevNode = NULL;
            this->nextNode = NULL;
            this->value = 0;
        }
};

class doublyLinkedList
{
    public:
        node *headNode;
        
        doublyLinkedList()
        {
            headNode = 0;
        }
        
        void traverse()
        {
            node *currentNode;
            currentNode = headNode;
            do
            {
                cout << currentNode->value << " ";
                currentNode = currentNode->nextNode;
            } while (currentNode != headNode);
            cout << endl;
        }
        
        void addAtBeginning(int val)
        {
            node *newNode = new node;
            newNode->value = val;
            if (headNode == NULL)
            {
                newNode->nextNode = newNode;
                newNode->prevNode = newNode;
                headNode = newNode;
            }
            else
            {
                node *lastNode;
                lastNode = headNode;
                while (lastNode->nextNode != headNode)
                {
                    lastNode = lastNode->nextNode;
                }
                lastNode->nextNode = newNode;
                newNode->nextNode = headNode;
                newNode->prevNode = lastNode;
                headNode->prevNode = newNode;
                headNode = newNode;
            }
        }
 
        
        void deleteAtStart()
        {
            if (headNode == NULL)
            {
                cout << "List is empty";
            }
            else
            {
                node *firstNode = headNode;
                node *lastNode = headNode;
                while (lastNode->nextNode != headNode)
                {
                    lastNode = lastNode->nextNode;
                }
                lastNode->nextNode = firstNode->nextNode;
                firstNode->nextNode->prevNode = lastNode;
                headNode = firstNode->nextNode;
                delete firstNode;
            }
        }        
        
        void deleteInMiddle(int val)
        {
            node *currentNode = headNode;
            node *pre;
            while (currentNode->value != val)
            {
                pre = currentNode;
                currentNode = currentNode->nextNode;
            }
            pre->nextNode = currentNode->nextNode;
            currentNode->nextNode->prevNode = pre;
            delete currentNode;
        }
        
       void deleteAtEnd()
        {
            node *temp = headNode;
            node *pre;
            while (temp->nextNode != headNode)
            {
            	pre=temp;
			    temp=temp->nextNode;
            }
            pre->nextNode=headNode;
            headNode->prevNode=pre;
            delete temp;
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
    list1.traverse();
    
    list1.deleteAtStart();
    cout << "Start deleted" << endl;
    list1.traverse();
    
    cout << "Middle deleted" << endl;
    list1.deleteInMiddle(3);
    list1.traverse();
    
    cout << "End deleted" << endl;
    list1.deleteAtEnd();
    list1.traverse();
    
    return 0;
}
