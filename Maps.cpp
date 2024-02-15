// Maps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

using namespace std;

class Queue {
private:
    struct Node {
        char* data;
        Node* next;
        Node(const char* value) {
            data = new char[strlen(value) + 1];
            strcpy(data, value);
            next = nullptr;
        }
        ~Node() {
            delete[] data;
        }
    };

    Node* frontPtr;
    Node* rearPtr;
    int size;

public:
    Queue() : frontPtr(nullptr), rearPtr(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    void enqueue(const char* value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            frontPtr = newNode;
        }
        else {
            rearPtr->next = newNode;
        }
        rearPtr = newNode;
        size++;
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
            size--;
            if (isEmpty()) {
                rearPtr = nullptr;
            }
        }
    }

    const char* front() const {
        if (!isEmpty()) {
            return frontPtr->data;
        }
        else {
            return nullptr;
        }
    }

    int getSize() const {
        return size;
    }
};

int main() {
    Queue charPtrQueue;
    charPtrQueue.enqueue("Hello");
    charPtrQueue.enqueue("World");
    charPtrQueue.enqueue("!");

    cout << "Queue size: " << charPtrQueue.getSize() << endl;
    cout << "Front element: " << charPtrQueue.front() << endl;

    charPtrQueue.dequeue();
    cout << "Queue size after dequeue: " << charPtrQueue.getSize() << endl;
    cout << "Front element after dequeue: " << charPtrQueue.front() << endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
