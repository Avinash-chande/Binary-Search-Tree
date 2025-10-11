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

Node *binary_tree()
{
    int x;
    cin >> x;
    if (x == -1)
        return NULL;
    Node *temp = new Node(x);
    // left
    cout << "enter the left child of " << x << ":";
    temp->left = binary_tree();

    // right
    cout << "enter the right child of " << x << ":";
    temp->right = binary_tree();
    // return address
    return temp;
}
int levelOrder(Node *root)
{
    int ans = 0;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        ans += curr->data;

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
    return ans;
}

int main()
{
    cout << "enter the root element :";
    Node *root;
    root = binary_tree();
    int ans = levelOrder(root);
    cout << ans;

    return 0;
}