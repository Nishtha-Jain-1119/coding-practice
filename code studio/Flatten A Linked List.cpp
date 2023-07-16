// Flatten A Linked List
// Sample Input 1 :
// 4
// 3
// 1 2 3
// 3
// 8 10 15
// 2
// 18 22
// 1
// 29
// Sample Output 1 :
// 1 2 3 8 10 15 18 22 29

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* merge(Node* left, Node* right){
	if(left == NULL){
		return right;
	}
	if(right == NULL){
		return left;
	}

	Node * ans = new Node(-1);
	Node* temp = ans;
	
	while(left != NULL && right != NULL){
		if(left->data <= right->data){
			temp->child = left;
			temp = left;
			left = left->child;
		}
		else{
			temp->child = right;
			temp = right;
			right = right->child;
		}
	}
	while(left){
		temp->child = left;
		temp = left;
		left = left->child;
	}
	while(right){
		temp->child = right;
		temp = right;
		right = right->child;
	}
	
	ans = ans->child;
	return ans;
}
Node* flattenLinkedList(Node* head) 
{
	// Base Case
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* left = head;
  // recursion call
	Node* sorted = flattenLinkedList(head->next);
	left->next = NULL;
	
	Node* result = merge(left, sorted);
	
	return result;
}
