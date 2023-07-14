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
// ----------------------------------------------------------another approach-----------------------------------------------------------------
