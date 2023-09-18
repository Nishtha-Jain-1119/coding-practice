#include <iostream>
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
void insert(Node* &tail, int element, int d){
    // node creation
    Node *temp = new Node(d);
    // empty list
    if(tail == NULL){
        tail = temp;
        temp->next = temp;
    }
    else{
        // assumig the element is in list
        Node *curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;

    }
}
// ----------------------------------------------------------------------------------------------------------------------------------------
void deletion(Node* &tail, int element){
    // empty list
    if (tail == NULL)
    {
        cout << "empty list!!" << endl;
        return;
    }
    
    Node *prev = tail;
    Node *curr = prev->next;
    while(curr->data != element){
        prev = curr;
        curr = curr->next;
    }

    // if there is only one node
    if(curr == prev){
        tail = NULL;
    }
    // if tail is curr node
    if(tail == curr){
        tail = prev;
    }
    prev->next = curr->next;
    curr->next = NULL; 
    delete curr;
}
// ----------------------------------------------------------------------------------------------------------------------------------------
void print(Node* tail){
    Node *store_tail = tail;
    do
    {
        cout << tail->data << "  ";
        tail = tail->next;
    } while (tail != store_tail);
    cout << endl;
}

// ----------------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    Node *tail = NULL;
    insert(tail, 3, 3);
    print(tail);
    insert(tail, 3, 4);
    print(tail);
    insert(tail, 4, 5);
    print(tail);
    insert(tail, 3, 6);
    print(tail);
    insert(tail, 4, 10);
    print(tail);

    deletion(tail,3);
    print(tail);
    return 0;
}