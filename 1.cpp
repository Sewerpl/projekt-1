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
     // usuwam element z początku listy
    void removeFromStart() {
        if (head == nullptr) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

      // usuwam element z końca listy
    void removeFromEnd() {
        if (tail == nullptr) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

// usuwam element ze wskazanym indeksem
    void removeAtIndex(int index) {
        if (index == 0) {
            removeFromStart();
            return;
        }

        Node* temp = head;
        int count = 0;

        while (temp != nullptr && count < index) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) return;

        if (temp == tail) {
            removeFromEnd();
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

        // wyświetlam całą listę
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // wyświetylam listę w odwrotnej kolejności 1
    void displayReverse() {
        Node* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
   
    // wyświetlam nastepny element od zadanego indeksu
    void displayNext(int index) {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr && count < index) {
            temp = temp->next;
            count++;
        }

        if (temp != nullptr && temp->next != nullptr) {
            std::cout << "Następny element: " << temp->next->data << std::endl;
        } else {
            std::cout << "Brak następnego elementu." << std::endl;
        }
    }

    // wyswietlam poprzedni element od zadanego indeksu
    void displayPrev(int index) {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr && count < index) {
            temp = temp->next;
            count++;
        }

        if (temp != nullptr && temp->prev != nullptr) {
            std::cout << "Poprzedni element: " << temp->prev->data << std::endl;
        } else {
            std::cout << "Brak poprzedniego elementu." << std::endl;
        }
    }




 
    return 0;
}
