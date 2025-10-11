#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

vector<int> preOrder(Node *root)
{
    // create a vector for storing  final ans
    vector<int> ans;
    if (root == nullptr)
        return ans;

    // create a stack for store a dta
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();
        ans.push_back(curr->data); // st.top ele put into vector as answer

        if (curr->right )
            st.push(curr->right); // put into stack
        if (curr->left)
            st.push(curr->left);
    }

    return ans;
}

vector<int> inOrder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<Node *> st;
    Node *curr = root;

    while (st.empty() == false || curr != NULL)
    {
        while (curr != NULL)
        {
            st.push(curr); // check all left using while loop jab tak curr null nahi ho jata
            curr = curr->left;
        }
        curr = st.top();
        st.pop();

        ans.push_back(curr->data); // store the top ele of stack  into ans

        curr = curr->right; // and then go right side
    }
    return ans;
}

vector<int> postOrder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<Node *> st1, st2;
    st1.push(root);
    Node *curr;

    while (!st1.empty())
    {
        // Pop from s1 and push it to s2
        curr = st1.top();
        st1.pop();
        st2.push(curr);

        // push into st1;
        if (curr->left)
            st1.push(curr->left);
        if (curr->right)
            st1.push(curr->right);
    }

    // put into vector
    while (!st2.empty())
    {
        curr = st2.top();
        st2.pop();
        ans.push_back(curr->data);
    }
    return ans;
}

vector<int>levelOrder(Node*root){
    vector<int>ans;
    if(root==NULL)return ans;

    queue<Node*>q;
    q.push(root);

    while (!q.empty())
    {
      Node*curr =q.front();
      q.pop();

      ans.push_back(curr->data);

      if(curr->left)q.push(curr->left);

      if(curr->right)q.push(curr->right);
    }
    return ans;
    
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> preorder = preOrder(root);
    cout << "preorder :";
    for (int val : preorder)
    {
        cout << val << " ";
    }
    cout << endl;

    vector<int> inorder = inOrder(root);
    cout << "inorder :";
    for (int val : inorder)
    {
        cout << val << " ";
    }
    cout << endl;

    vector<int> postorder = postOrder(root);
    cout << "postorder :";
    for (int val : postorder)
    {
        cout << val << " ";
    }
    cout << endl;

    vector<int> levelorder = levelOrder(root);
    cout << "levelorder :";
    for (int val : levelorder)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}