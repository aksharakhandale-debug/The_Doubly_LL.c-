#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert a new node at the end of the list
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete a node by value
    void deleteValue(int val) {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        // If head node itself needs to be deleted
        if (head->data == val) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        // Traverse the list to find the value
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        // If value was not found
        if (temp == nullptr) {
            std::cout << "Value not found in the list\n";
            return;
        }

        // If it's a middle or last node
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        delete temp;
    }

    // Display elements from front to back
    void displayForward() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }
        
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // Display elements from back to front (demonstrating backward traversal)
    void displayBackward() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }
        
        Node* temp = head;
        // Go to the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        // Traverse backwards using prev pointer
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        std::cout << "NULL\n";
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    
    std::cout << "Forward Display:  ";
    list.displayForward();

    std::cout << "Backward Display: ";
    list.displayBackward();

    list.deleteValue(20);
    std::cout << "\nAfter deleting 20:\n";
    std::cout << "Forward Display:  ";
    list.displayForward();

    return 0;
}
