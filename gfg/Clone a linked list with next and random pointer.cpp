// Clone a linked list with next and random pointer
// You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b (arb is pointer to random node).
// Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
// For example, if there are two nodes X and Y in the original list, where X.arb --> Y, then for the corresponding two nodes x and y in the copied list, x.arb --> y.

// ---------------------------------------------------1st approach with tc-O(n) and sc-O(n)--------------------------------------------------------------------------
class Solution
{   
    void print(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
    public:
    Node *copyList(Node *head)
    {
        map<Node* ,Node*>mapping;
        //step-1 create clone list using next pointers and also store the mapping

        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp != NULL){
            Node* n1 = new Node(temp->data);
            if(cloneTail == NULL){
                cloneHead = n1;
                cloneTail = n1;
            }
            else{
                cloneTail->next = n1;
                cloneTail = cloneTail->next;
            }
            mapping[temp] = n1;
            temp = temp->next;

        }
        Node* curr = cloneHead;
        temp = head;
        while(curr != NULL){
            curr->arb = mapping[temp->arb];
            curr = curr->next;
            temp = temp->next;
        }
        return cloneHead;
    }

};

// --------------------------------------------------2nd approach with tc-O(n) and sc-O(1)------------------------------------------------------------------------
class Solution
{
    public:
    Node *copyList(Node *head)
    {
        // step-1 clone the list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp != NULL){
            Node* n1 = new Node(temp->data);
            if(cloneTail == NULL){
                cloneHead = n1;
                cloneTail = n1;
            }
            else{
                cloneTail->next = n1;
                cloneTail = cloneTail->next;
            }
            temp = temp->next;
        }
        
        // step-2 Add cloneNodes in between original list
        Node* orignal = head;
        Node* clone = cloneHead;
        Node* next = NULL;
        while(orignal != NULL && clone != NULL){
            next = orignal->next;
            orignal->next = clone;
            orignal = next;
            
            next = clone->next;
            clone->next = orignal;
            clone = next;
        }
        
        // step-3 set random pointer for clone list
        Node* curr = head;
        while(curr != NULL){
            // if temp->random is NULL 
            curr->next->arb = curr->arb ? curr->arb->next : curr->arb;
            
            curr = curr->next->next;
        }

        // step-4 revert changes from step-2
        orignal = head;
        clone = cloneHead;
        while(orignal != NULL && clone != NULL){
            orignal->next = clone->next;
            orignal = orignal->next;
            if(orignal == NULL){
                clone->next = orignal;
            }
            else{
                clone->next = orignal->next;
            }
            clone = clone->next;
        }
        
        
        // step-5 return ans;
        return cloneHead;
    }

};
