#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    // constructors
    Node()
    {
    }

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        this->next = NULL;
        this->prev = NULL;
        cout << "memory is free of node :- " << value << endl;
    }
};

// ----------------------------------------------------------------------------------------------------------------------------------------
int getLength(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
// ----------------------------------------------------------------------------------------------------------------------------------------
void insertAt_head(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
// ----------------------------------------------------------------------------------------------------------------------------------------
void insertAt_tail(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
// ----------------------------------------------------------------------------------------------------------------------------------------
void insertIn_middle(Node *&head, Node *&tail, int d, int pos)
{
    if (pos == 1)
    {
        insertAt_head(head, tail, d);
        return;
    }
    Node *temp = head;
    int index = 1;
    while (index < pos - 1)
    {
        temp = temp->next;
        index++;
    }
    if (temp->next == NULL)
    {
        insertAt_tail(head, tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);

    // using another pointer
    // Node *temp2 = temp->next;
    // nodeToInsert->next = temp2;
    // nodeToInsert->prev = temp;
    // temp->next = nodeToInsert;
    // temp2->prev = nodeToInsert;

    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
}
// ----------------------------------------------------------------------------------------------------------------------------------------
void deletion(Node *&head, Node *&tail, int pos)
{
    Node *temp = head;
    // first position
    if (pos == 1)
    {
        head = head->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    // out of linkedlist position
    else if(pos>getLength(head)){
        cout << "position does not exit!!" << endl;
    }
    else
    {
        int index = 1;
        while (index < pos)
        {
            temp = temp->next;
            index++;
        }
        // last position
        if (temp->next == NULL)
        {
            tail = temp->prev;
            tail->next = NULL;
            delete temp;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
}
// ----------------------------------------------------------------------------------------------------------------------------------------
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
// ----------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *n1 = new Node(10);
    head = n1;
    tail = n1;
    print(head);
    insertAt_head(head, tail, 12);
    print(head);
    // cout << getLength(head) << endl;

    insertAt_tail(head, tail, 34);
    print(head);
    // cout << getLength(head) << endl;

    insertIn_middle(head, tail, 60, 3);
    insertIn_middle(head, tail, 55, 4);
    insertIn_middle(head, tail, 5, 3);
    print(head);

    deletion(head, tail, 5);
    print(head);

    return 0;
}