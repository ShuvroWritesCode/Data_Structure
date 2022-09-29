#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for node with data" << value << '\n';
    }
};

void InsertAtHead(Node* &head, int d){
    //create new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

}

void InsertAtBack(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void InsertAtMiddle(Node* &tail, Node* &head, int Position, int d){

    //Insert at the beginning
    if(Position == 1){
        InsertAtHead(head, d);
        return;
    }

    //Traversing Node to insert at any position
    Node* temp = head;
    int count = 1;

    while(count < Position-1){
        temp = temp -> next;
        count++;
    }

    //Insert at the last
    if(temp -> next == NULL){
        InsertAtBack(tail, d);
        return;
    }

    //Creating Node to be inserted
    Node* NodeToInsert = new Node(d);
    NodeToInsert -> next = temp -> next;
    temp -> next = NodeToInsert;
}

void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
}

void DeleteNode(int Position, Node* &head){
  
    //Deleting first node
    if(Position == 1){
        Node* temp = head;
        head = head -> next;
        //memory free
        temp -> next = NULL;
        delete temp;
    }
    //deleting any middle node or last node
    else{
        Node *curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < Position){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int32_t main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    InsertAtHead(head, 12);
    InsertAtHead(head, 15);
    Node* tail = node1;
    InsertAtBack(tail, 200);
    InsertAtMiddle(tail, head, 2, 21);

    DeleteNode(2, head);
    display(head);

    return 0;
}
