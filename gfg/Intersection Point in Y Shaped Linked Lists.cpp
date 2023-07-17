// Intersection Point in Y Shaped Linked Lists
// Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.
// Input: 
// Linked List 1 = 4->1->common
// Linked List 2 = 5->6->1->common
// common = 8->4->5->NULL
// Output: 8
// Explanation: 
// 4              5
// |              |
// 1              6
//  \             /
//   8   -----  1 
//    |
//    4
//    |
//   5
//   |
//   NULL

int detectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            break;
        }
    }
    // if loop is absent
    if(fast == NULL || fast->next == NULL){
        return -1;
    }
    
    // finding the starting point;
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}
int intersectPoint(Node* head1, Node* head2)
{
    // step-1 make 1 linkedlist circular
    Node* curr1 = head1;
    while(curr1->next != NULL){
        curr1 = curr1->next;
    }
    Node * temp = curr1;
    curr1->next = head1;
    
    // step-2 the find starting of loop 
    int ans = detectLoop(head2);
    temp->next = NULL;
    return ans;
    // return 15;
}
