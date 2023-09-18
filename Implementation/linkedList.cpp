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
        cout << "memory is free of node :- " << value << endl;
    }
};

// ----------------------------------------------------------------------------------------------------------------------------------------
// inserion at the starting
void insertAt_head(Node *&head,Node *&tail, int d)
{
    Node *n1 = new Node(d);
    if (head == NULL)
    {
        head = n1;
        tail = n1;
    }
    else
    {
        n1->next = head;
        head = n1;
    }
}
// ----------------------------------------------------------------------------------------------------------------------------------------
// insertion at last
void insertAt_tail(Node *&head,Node *&tail, int d)
{
    Node *n1 = new Node(d);
    if (tail == NULL)
    {
        tail = n1;
        head = n1;
    }
    else
    {
        tail->next = n1;
        tail = n1;
    }
}
// ----------------------------------------------------------------------------------------------------------------------------------------
// insertion at specific postion
void insertIn_middle(Node *&head, Node *&tail, int d, int position)
{
    // insering at head
    if (position == 1)
    {
        insertAt_head(head,tail, d);
        return;
    }
    Node *temp = head;
    int index = 1;
    while (index < position - 1)
    {
        temp = temp->next;
        index++;
    }
    // inserting at tail
    if (temp->next == NULL)
    {
        insertAt_tail(head,tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
// ----------------------------------------------------------------------------------------------------------------------------------------
// traverse the linkedlist
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

// ----------------------------------------------------------------------------------------------------------------------------------------
void deletion(Node *&head, Node *&tail, int position)
{
    // first node
    if (position == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    // deleting any middle node or last node
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int index = 1;
        while (index < position)
        {
            prev = curr;
            curr = curr->next;
            index++;
        }
        if (curr->next == NULL)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
// ----------------------------------------------------------------------------------------------------------------------------------------
// without using recursion and using forwad pointer
void reverse(Node* & head, Node* & tail){
    tail = head;
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}
// ----------------------------------------------------------------------------------------------------------------------------------------
// reverse function using recursion
void rev(Node* &head, Node* &tail, Node* curr, Node* prev){
    // base case
    if(curr == NULL){
        tail = head;
        head = prev;
        return;
    }
    Node *forward = curr->next;
    curr->next = prev;
    // ek case kr liya baki recursion sambhal lega
    rev(head, tail, forward, curr);
}
// ----------------------------------------------------------------------------------------------------------------------------------------
// another recursion approach
Node* reverseList(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *chotaHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return chotaHead;
}


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
        if(fast == slow){
            return true;
        }
    }
    return false;
}

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
    return slow;
}


// ----------------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    Node *n1 = new Node(20);
    Node *head = n1;
    Node *tail = n1;
    insertAt_tail(head,tail, 21);
    insertAt_tail(head,tail, 22);
    insertAt_tail(head,tail, 23);
    insertAt_tail(head,tail, 24);
    insertAt_tail(head,tail, 25);
    insertAt_tail(head,tail, 26);
    insertAt_tail(head,tail, 22);
    // insertIn_middle(head, tail, 2, 5);
    print(head);
    // cout << "head:- " << head->data << endl
    //      << "tail:- " << tail->data << endl;
    // deletion(head, tail, 2);
    // print(head);
    // cout << "head:- " << head->data << endl
    //      << "tail:- " << tail->data << endl;
    // deletion(head, tail, 4);
    // print(head);
    cout << "head:- " << head->data << endl;
    cout << "tail:- " << tail->data << endl;
    // rev(head,tail,head,NULL);
    // print(head);
    // cout << "head:- " << head->data << endl
    //      << "tail:- " << tail->data << endl;
    // Node *h1 = reverseList(head);
    // print(h1);
    tail->next = head->next->next->next;
    Node *t1 = FloydDetectLoop_WithStarting_Node(head);
    cout <<"starting of loop: "<< t1->data<<endl;
    // if(FloydDetectLoop(head)){
    //     cout << "Loop is in Linkedlist" << endl;
    // }else{
    //     cout << "No loop in Linkedlist" << endl;
    // }

    return 0;
}