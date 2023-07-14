// 83. Remove Duplicates from Sorted List
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* NodeToDelete = NULL;
        while(curr != NULL){
            if(curr->next != NULL && curr->val == curr->next->val){
                NodeToDelete = curr->next;
                curr->next = curr->next->next;
                NodeToDelete->next = NULL;
                delete NodeToDelete;

            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};