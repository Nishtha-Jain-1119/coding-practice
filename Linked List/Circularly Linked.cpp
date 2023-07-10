// Circularly Linked
// Sample Input 1 :
// 1
// 5
// 1 2 3 4 1
// Sample Output 1 :
// True
// #include <bits/stdc++.h> 

/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/

bool isCircular(Node* head){
    // Write your code here.
    if(head == NULL){
        return true;
    }
    if (head -> next == NULL) {
        return false;
    }
    Node * fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL && slow != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(slow == fast && slow == head){
        return true;
    }
    return false;
}
