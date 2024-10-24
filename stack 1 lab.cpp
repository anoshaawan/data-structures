#include <iostream>
using namespace std;
#define MAX 3 
class PlateStack{
private:
    int stack[MAX];  
    int top;         
public:
    PlateStack(){
        top=-1;  
    }
    void push(int plate) {
        if (top == MAX - 1) {
            cout << "Stack is full" << endl;
        } else {
            top++;
            stack[top] = plate;
            cout << "Plate " << plate << " added to the stack." << endl;
        }
    }
    void pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Plate " << stack[top] << " removed from the stack." << endl;
            top--;
        }
    }
    void peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Plate " << stack[top] << " is on top of the stack." << endl;
        }
    }
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top == MAX - 1);
    }
};

int main() {
    PlateStack plates;
    int choice, plate;
    do {
        cout << "\n1. Add a plate\n2. Remove the top plate\n3. Check top plate\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter plate number to add: ";
                cin >> plate;
                plates.push(plate);
                break;
            case 2:
                plates.pop();
                break;
            case 3:
                plates.peek();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}