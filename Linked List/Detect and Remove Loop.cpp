// Detect and Remove Loop
// Sample Input:
// 6 2
// 1 2 3 4 5 6 
// Sample Output:
// 1 2 3 4 5 6

/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node *removeLoop(Node *head)
{
// empty list
    if(head == NULL){
        return head;
    }
// detecting loop
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && slow != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            break;
        }
    }
  // loop is not present
    if(fast == NULL){
        return head;
    }
  // loop is present and finding the strating point of loop
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
  // traversing to the end of the loop and making it to NULL
    Node* temp = slow;
    while(temp->next != slow){
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
