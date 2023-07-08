// Reverse List In K Groups
// Sample Input 1:
// 6
// 5 4 3 7 9 2
// 4 
// Sample Output 1:
// 7 3 4 5 9 2

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
int getLength(Node* head){
    Node* temp = head;
    int cnt = 1;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
Node* kReverse(Node* head, int k) {
    // Write your code here.
    // base case
    if(head == NULL){
        return NULL;
    }
    int n = getLength(head);
    if(n < k){
        return head;
    }
    // step 1 - reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    // Node* forward2 = head;
    int cnt = 0;
    while(cnt<k && curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }

    // step 2 -  recursion call
    if(forward != NULL)
    {
        head->next = kReverse(forward, k);
    }

    // step 3 - return 
    return prev;

}
