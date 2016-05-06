#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* head; //global variable

//---------- INSERT ----------//
Node* Insert(Node* head, int x){
    //Node* temp = (Node*)malloc(sizeof(struct Node));
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}

//---------- PRINT ----------//
void Print(Node* head){
    cout << "List: ";
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//---------- REVERSE ----------//
struct Node* Reverse(struct Node* head){
    
    //current: store the address of the current node
    //prev: store the address of the previous node
    //next: store the address of the next node
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    
    //traverse the list
    while(current != NULL){
        
        //fix the link
        next = current->next;
        current->next = prev;
        
        //move prev and cureent
        prev = current; //move prev to current
        current = next; //move current to next
    }
    head = prev; //new head
    return head;
}

//---------- MAIN ----------//
int main() {
    struct Node* head = NULL; //local variable
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    Print(head);
    head = Reverse(head);
    Print(head);
}
