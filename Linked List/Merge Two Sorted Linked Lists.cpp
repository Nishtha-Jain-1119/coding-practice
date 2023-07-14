// Merge Two Sorted Linked Lists
// Sample Input 1:
// 2
// 1 4 5 -1
// 2 3 5 -1
// 7 8 -1
// 1 3 4 6 -1
// Sample Output 1:
// 1 2 3 4 5 5 -1
// 1 3 4 6 7 8 -1

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* solve(Node<int>* first, Node<int>* second)
{
    Node<int>* curr1 = first;
    Node<int>* next1 = first->next;
    Node<int>* curr2 = second;
    Node<int>* next2 = second->next;
    while(curr2 != NULL && next1 != NULL){
        if(curr1->data <= curr2->data && curr2->data <= next1->data){
            // add node in between first list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            // update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            // aage badado
            curr1 = curr1->next;
            next1 = next1->next;
            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    // if first is single node linkedlist
    if(next1 == NULL){
        curr1->next = curr2;
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    // checking the smaller head in both linked lists
    if(first->data <= second->data){
        return solve(first, second);
    }
    else{
        return solve(second, first);
    }

}
