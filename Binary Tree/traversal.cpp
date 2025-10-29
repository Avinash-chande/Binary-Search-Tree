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
        left = right = NULL;
    }
};
void preOrder(Node *root)
{
    // base condition
    if (root == NULL)
        return;

    // Node
    cout << root->data << " ";
    // left
    preOrder(root->left);
    // right
    preOrder(root->right);
}
void inOrder(Node *root)
{
    // base condition
    if (root == NULL)
        return;

    // left
    inOrder(root->left);
    // Node
    cout << root->data << " ";
    // right
    inOrder(root->right);
}
void postOrder(Node *root)
{
    // base condition
    if (root == NULL)
        return;

    // left
    postOrder(root->left);
    // right
    postOrder(root->right);
    // Node
    cout << root->data << " ";
}
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

int main()
{
    cout << "enter the root element :";
    Node *root;
    root = binary_tree();

    cout << "PreOrder :";
    preOrder(root);

    cout << "\nInOrder :";
    preOrder(root);

    cout << "\nPostOrder :";
    postOrder(root);

    return 0;
}

  // your input  like this 1,2,3,4,-1,-1,5,-1,-1,-1,6,-1,-1

/* enter the root element :1
enter the left child of 1:2
enter the left child of 2:3
enter the left child of 3:4
enter the left child of 4:-1
enter the right child of 4:-1
enter the right child of 3:5
enter the left child of 5:-1
enter the right child of 5:-1
enter the right child of 2:-1
enter the right child of 1:6
enter the left child of 6:-1
enter the right child of 6:-1
PreOrder :1 2 3 4 5 6
InOrder :1 2 3 4 5 6
PostOrder :4 5 3 2 6 1   */