// Rotate a Linked List
// Input:
// N = 8
// value[] = {1, 2, 3, 4, 5, 6, 7, 8}
// k = 4
// Output: 5 6 7 8 1 2 3 4

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        int n = 1;
        // curr is alredy on head so n = 1 not 0
        Node* curr = head;
        Node* newHead = NULL;
        while(n<k){
            curr = curr->next;
            n++;
        }
        // curr is on last node means k = no. of nodes
        if(curr->next == NULL){
            return head;
        }
        newHead = curr->next;
        curr->next = NULL;
        curr = newHead;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = head;
        return newHead;
    }
};
