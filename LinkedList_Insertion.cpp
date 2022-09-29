#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
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
//        cout << temp -> next << '\n';
        temp = temp -> next;
    }
}

int32_t main() {
    //created a new node
    Node* node1 = new Node(10);
    /*
    cout << node1 -> data << '\n';
    cout << node1 -> next << '\n';
    */

    //head pointed to new node
    Node* head = node1;
    InsertAtHead(head, 12);
    InsertAtHead(head, 15);
    display(head);

    cout << '\n';

    Node* tail = node1;
    InsertAtBack(tail, 200);
    display(head);

    cout << '\n';

    InsertAtMiddle(tail, head, 2, 21);
    display(head);

    cout << '\n' << "head " << head -> data << '\n';
    cout << '\n' <<  "tail " << tail -> data << '\n';

    return 0;
}
