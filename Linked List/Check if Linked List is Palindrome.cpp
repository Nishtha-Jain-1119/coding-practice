// Check if Linked List is Palindrome

#include <bits/stdc++.h> 
class Solution{
  public:
    //Function to check whether the list is palindrome.-----<<<< using array with TC =O(n) and SC = O(n) >>>>-----------------------------
    bool isPalindrome(Node *head)
    {
        //Your code here
        vector<int> arr;
        Node* curr = head;
        while(curr != NULL){
            arr.push_back(curr->data);
            curr = curr->next;
        }
        int i = 0;
        int j = arr.size() - 1;
        while(i<j){
            if(arr[i] == arr[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
// -------------------------------------------------another approach---with TC-O(n) and SC-O(1)----------------------------------------------
class Solution{
  private:
    // function to find mid
    Node* findMid(Node* head)
    {
        Node* slow = head;
        Node* fast = head->next;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // function to reverse a list
    Node* reverseList(Node* head)
    {
        if(head->next == NULL){
            return head;
        }
        Node* curr = head;
        Node* prev = NULL;
        Node* forward = NULL;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head->next == NULL){
            return true;
        }
        
        // step-1 get mid node
        Node* mid = findMid(head);
        
        // step-2 reverse the second half if linkedlist
        Node* head2 = reverseList(mid->next);
        mid->next = NULL;
        
        // now compare both lists
        Node* head1 = head;
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->data != head2->data){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};
