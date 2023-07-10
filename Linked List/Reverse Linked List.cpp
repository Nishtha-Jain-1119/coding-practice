// Reverse Linked List
// Sample Input 1 :
// 1
// 1 2 3 4 5 6 -1
// Sample Output 1 :
// 6 5 4 3 2 1 -1

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head == NULL || head->next == NULL){
        return head;
    }

    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
// -----------------------------------------------------------------------------------------------------------------------------------------------------------
// using recursion
void reverse(LinkedListNode<int>* &head, LinkedListNode<int> *curr,
                LinkedListNode<int> *prev){

    // base case
    if(curr == NULL){
        head = prev;
        return ;
    }
    LinkedListNode<int> *forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    reverse(head, curr, prev);
    
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    reverse(head, curr, prev);
    return head;
}
// ------------------------------------------------------------------------------------------------------------------------------------------------------
// another recusion code with the samo appraoch
void reverse(LinkedListNode<int>* &head, LinkedListNode<int> *curr,
                LinkedListNode<int> *prev){

    // base case
    if(curr == NULL){
        head = prev;
        return ;
    }

    reverse(head, curr->next, curr);
    curr->next = prev;
    
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    reverse(head, curr, prev);
    return head;
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------
// another recursion approach
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head == NULL || head->next == NULL){
        return head;
    }
    LinkedListNode<int> * chotaHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}
