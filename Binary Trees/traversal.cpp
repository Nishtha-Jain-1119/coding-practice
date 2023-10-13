// ------------------IN ORDER FUNCTION-----------<<left-root-right>>-------------
void inOrder(Node* curr){
    // base case
    if(curr == NULL){
        return;
    }

    inOrder(curr->left);
    cout << curr->data<<" ";
    inOrder(curr->right);
}
void inOrder(Node *root)
{
    stack<Node *> s;
    Node *temp = root;

    // --- go to left till null then print it and then come back ---
    while (true)
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            if (s.empty() == true)
                break;
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}

// ------------------PRE ORDER FUNCTION--------------<<root-left-right>>--------
void preOrder(Node* curr){
    // base case
    if(curr == NULL){
        return;
    }

    cout << curr->data<<" ";
    preOrder(curr->left);
    preOrder(curr->right);
}
void preOrder(Node *root)
{
    stack<Node *> s;
    if (root == NULL)
    {
        return;
    }
    s.push(root);
    // --- take right first then left ---
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
}

// -------------POST ORDER FUNCTION -----------<<left-right-root>>----------
void postOrder(Node* curr){
    // base case
    if(curr == NULL){
        return;
    }

    postOrder(curr->left);
    postOrder(curr->right);
    cout << curr->data<<" ";
}
// ----->> using two stacks <<----
void postOrder(Node *root)
{
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while (!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left)
        {
            s1.push(temp->left);
        }
        if (temp->right)
        {
            s1.push(temp->right);
        }
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}
// ----->> using one stack <<----
// go to left left left... till null then go to right then again left till null and
// when both left and right subtree are done then print node
void postOrder_2(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    Node *temp = NULL;
    while (curr != NULL || !s.empty())
    {
        if (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = s.top()->right;
            if (temp == NULL)
            {
                temp = s.top();
                s.pop();
                cout << temp->data << " ";
                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    cout << temp->data << " ";
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
}

// -----------LEVEL ORDER TRAVERSAL -------<<bfs>>------
void level_Order(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);   //seperator

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;  //purana level complete ho gaya
            if(!q.empty()){
                q.push(NULL);  //for next level
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }    
}
vector<vector<int>> level_Order(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}
