#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

       // dodaje element do listy
    void addAtStart(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

        // dodaje element na koniec listy
    void addAtEnd(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
     // dodaje element pod indeks, który wskazałem
    void addAtIndex(int val, int index) {
        if (index == 0) {
            addAtStart(val);
            return;
        }

        Node* temp = head;
        int count = 0;

        while (temp != nullptr && count < index) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            addAtEnd(val);
        } else {
            Node* newNode = new Node(val);
            newNode->prev = temp->prev;
            newNode->next = temp;
            temp->prev->next = newNode;
            temp->prev = newNode;
        }
    }




 
    return 0;
}
