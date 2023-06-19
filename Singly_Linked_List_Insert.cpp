#include <iostream>
#include <memory>

// Using 'nampespace std;' is considered as bad programming practice.

class Node {
    public:
        int data;
        std::unique_ptr<Node> next;
    //Unparameterized constructor
    Node() {
        data = -1;
        next = nullptr;
    }
    //Parameterized constructor
    explicit Node (int data) {
        this->data = data;
        this->next = nullptr;
    }
};
  
class LinkedList {
    public:
        std::unique_ptr<Node> head;
        Node *tail;
        // Unparameterized constructor
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }
        ~LinkedList() {
            std::cout << "\nList has been destroyed..!!";
        }
        void Insert(int data);
        void Display();
};

void LinkedList::Insert(int data) {
    // Check if the list is empty and if empty make the newNode as head and tail.
    if (head == nullptr) {
        head = std::make_unique<Node>(data);
        tail = head.get();
        return;
    }
    // If the LinkedList is not empty, traverse to the end of the list and add the newNode.
    tail->next = std::make_unique<Node>(data);
    tail = tail->next.get();
}

void LinkedList::Display() {
    //Check if the list is empty.
    if (head == nullptr) {
        std::cout  << "List is empty\n";
        return;
    }
    //Traverse to each node and display the data of the node.
    Node *temp = head.get();
    while (temp != nullptr) {
        std::cout  << temp->data << " ";
        temp = temp->next.get();
    }
}

int main() {

    // Object of class LinkedList.
    LinkedList l;
    int temp,ch;
    //Menu driven program.
    do {
        std::cout  << "\t\t      MENU\n";
        std::cout  << "\t\t1.Insert\n";
        std::cout  << "\t\t2.Display\n";
        std::cout  << "\t\t3.Exit\n";
        std::cout << "Enter your choice: [  ]\b\b";
        std::cin >> ch;
        switch(ch) {
                case 1:
                    std::cout << "\nEnter the element to be inserted: ";
                    std::cin >> temp;
                    l.Insert(temp);
                break;
                case 2:
                    l.Display();
                break;
                case 3:
                    return 0;
                break;
                default: 
                    std::cout << "\nInvalid choice..!!";
                break;
        }
    }while(ch != 3);
}