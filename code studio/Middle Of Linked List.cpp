// Middle Of Linked List
// Sample Input 1 :
// 5
// 1 2 3 4 5
// Sample Output 1 :
// 3 4 5

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

// using two pointer approach --fast and slow
Node *findMiddle(Node *head) {
    // for empty list or single node
    if(head == NULL || head->next == NULL){
        return head;
    }
    // for two node in a list;
    else if(head->next->next == NULL){
        return head->next;
    }
    else{
        Node* fast = head->next;
        Node* slow = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
}

// the iterative approach
int getLength(Node *head){
    int index = 1;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        index++;
    }
    return index;
}
Node *findMiddle(Node *head) {
    // Write your code here
    int len = getLength(head);
    int mid = len/2 +1;
    Node* temp = head;
    int index = 1;
    while(index<mid){
        temp = temp->next;
        index++;
    }
    return temp;
}


