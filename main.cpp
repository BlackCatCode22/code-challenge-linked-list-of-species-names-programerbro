#include <iostream>
#include <string>
using namespace std;


struct node {
    string data;
    node* next;

    node(const string& val) : data(val), next(nullptr) {}
};

class Animalnames {
public:
    Animalnames() : head(nullptr) {}


    void insert(const string& val) {
        node* newNode = new node(val);
        if (!head) {
            head = newNode;
        } else {
            node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }


    bool search(const string& val) {
        node* current = head;
        while (current) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }


    void display() {
        node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

private:
    node* head;
};

int main() {
    cout << " Welcome to Animal Names list!" << endl;
    Animalnames animalList;
    string inputValue;


    animalList.insert("Hyena");
    animalList.insert("Lion");
    animalList.insert("Bear");
    animalList.insert("Tiger");


    cout << "Enter an animal species to search for: ";
    getline(cin, inputValue);


    if (animalList.search(inputValue)) {
        cout << "Animal species found in the linked list." << endl;
    } else {
        cout << "Animal species not found in the linked list." << endl;
    }


    cout << "Linked List of Animal species: ";
    animalList.display();

    return 0;
}
