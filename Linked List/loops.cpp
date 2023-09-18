#include <iostream>
#include<map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node()
    {
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~Node()
    {
        int value = this->data;
        cout << "memory is free of Node :- " << value << endl;
    }
};

// if linklist is circular or not  [--->tail->next must be = head<---]
// -----------------------------------------------------------------------------------------------------------------------------------------
bool isCircular(Node *head){
    // empty list
    if(head == NULL){
        return true;
    }
    Node *temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    if(temp == head){
        return true;
    }
    return false;
}

// detect loop in linkedlist  [-->loop can be anywhere just tail->next is not equal to NULL<--]
// -----------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------using map------------------------------------------------------------------------
bool detectLoop(Node* head){
    // empty list
    if(head == NULL){
        return false;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while(temp != NULL){
        // loop is present
        if(visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// detect loop using --------> Floyd’s cycle detction algorithm or Hare-Tortoise algorithm
// -----------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------using two pointers-----------------------------------------------------------------
bool FloydDetectLoop(Node* head){
    // empty list
    if(head == NULL){
        return false;
    }
    Node *fast = head;
    Node *slow = head;
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        // loop is present
        if(fast == slow){
            return true;
        }
    }
    return false;
}

// ----------------------------------------------------------Hare-Tortoise algorithm-------------------------------------------------------
Node* findMid(Node* head){
    Node* fast = head->next;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// finding the starting point of loop using Floyd’s cycle detction algorithm
Node* FloydDetectLoop_WithStarting_Node(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node *fast = head;
    Node *slow = head;
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        // loop is present
        if(fast == slow){
            break;
        }
    }
    // no loop is present
    if(fast == NULL){
        return NULL;
    }
    cout << "loop is present" << endl;
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    // slow is the starting point of loop 
    return slow;
}
