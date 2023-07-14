// Sort linked list of 0s 1s 2s
// Sample Input 1:
// 7
// 1 0 2 1 0 2 1
// Sample Output 1:
// 0 0 1 1 1 2 2

// -------------------------------------------using count variables and replacing the data of node-----------------------------------------------------------------
Node* sortList(Node *head){
    // Write your code here.
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            count0++;
        }
        else if(temp->data == 1){
            count1++;
        }
        else{
            count2++;
        }
        temp = temp->next;
    }
    temp = head;
    while(count0 != 0){
        temp->data = 0;
        temp = temp->next;
        count0--;
    }
    while(count1 != 0){
        temp->data = 1;
        temp = temp->next;
        count1--;
    }
    while(count2 != 0){
        temp->data = 2;
        temp = temp->next;
        count2--;
    }
    return head;
}


// ---------------------------------------without replacing -> by creating three new linkedlist and joining them---------------------------------------------------
