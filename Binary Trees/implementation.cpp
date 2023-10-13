#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// ------class defination-----------
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(){}
    Node(int x){
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

// recursive function-----------------------
Node* buildTree(Node* root){
    cout << "Enter data of the node: "<<endl;
    int d;
    cin>>d;
    // base case
    if(d == -1){
        return NULL;
    }
    root = new Node(d);
    cout << "Enter for inserting for left of " << d << " node"<<endl;
    root->left = buildTree(root->left);
    cout << "Enter for inserting for right of " << d << " node"<<endl;
    root->right = buildTree(root->right);
    return root;
}

// -----------------------------------------------------
Node *buildTree_levelOrder(Node *root)
{
    queue<Node *> q;
    int d;
    cout << "Enter data for root: ";
    cin >> d;
    root = new Node(d);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter data for left of " << temp->data << " : ";
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter data for right of " << temp->data << " : ";
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}
