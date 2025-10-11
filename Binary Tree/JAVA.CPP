#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

public:
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void helper(Node *root, int low, int high, vector<int>&ans)
{

           if (!root) return;

    // If root's data is greater than low, explore left subtree
    if (root->data > low)
        helper(root->left, low, high, ans);

    // if root's data in between the given range
    if (root->data >= low && root->data <= high)
        ans.push_back(root->data);

    // If root's data is smaller than high, explore right subtree
    if (root->data < high)
        helper(root->right, low, high, ans);
}


vector<int> printNearNodes(Node *root, int low, int high)
{
    vector<int> ans;
    helper(root, low, high, ans);
    return ans;
}

int main()
{
    Node *root = new Node(17);
    root->left = new Node(4);
    root->right = new Node(18);
    root->left->left = new Node(2);
    root->left->right = new Node(9);

    vector<int> range = printNearNodes(root, 4, 24);
    cout << "range :";
    for (int val : range)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}