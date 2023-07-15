// Add two numbers represented by linked lists
// Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

// For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    // reverse function
    struct Node* reverse(struct Node* head){
        if(head->next == NULL){
            return head;
        }
        struct Node* curr = head;
        struct Node* prev = NULL;
        struct Node* forward = NULL;
        while(curr != 0){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    // insert at head function so we don't need to reverse the ans linkedlist again.
    void insert(struct Node* &head, int val){
        struct Node* temp = new Node(val);
        temp->next = head;
        head = temp;
    }

    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // step-1 reverse both linkedlists
        
        first = reverse(first);
        second = reverse(second);
        
        // add both linkedlists
        
        struct Node* anshead = NULL;
        
        int carry = 0;
        int digit, sum;
        while(first != NULL && second != NULL){
            sum = first->data + second->data + carry;
            carry = sum/10;
            digit = sum%10;
            insert(anshead, digit);
            first = first->next;
            second = second->next;
        }
        while(first != NULL){
            sum = first->data  + carry;
            carry = sum/10;
            digit = sum%10;
            insert(anshead, digit);
            first = first->next;
        }
        while(second != NULL){
            sum = second->data + carry;
            carry = sum/10;
            digit = sum%10;
            insert(anshead, digit);
            second = second->next;
        }
        if(carry>0){
            insert(anshead, carry);
        }

        return anshead;
    }
};
