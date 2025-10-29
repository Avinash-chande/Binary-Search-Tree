#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        height = 1;
        left = right = nullptr;
    }
};

int getHight(Node *root)
{
    if (!root)
        return 0;

    return root->height;
}

int getBlanced(Node *root)
{
    return getHight(root->left) - getHight(root->right);
}

// right Rotation (L L)
Node *rightRotation(Node *root)
{
    Node *child = root->left; // create a child
    Node *childRight = child->right;

    child->right = root;     // connect root to child right
    root->left = childRight; // and connect remeaing childRight

    // update the height
    root->height = 1 + max(getHight(root->left), getHight(root->right));
    child->height = 1 + max(getHight(child->left), getHight(child->right));

    return child;
}
// left Rotation (R R)
Node *leftRotation(Node *root)
{

    Node *child = root->right; // create a child
    Node *childLeft = child->left;

    child->left = root;      // connect root to child right
    root->right = childLeft; // and connect remeaing childRight

    // update the height
    root->height = 1 + max(getHight(root->left), getHight(root->right));
    child->height = 1 + max(getHight(child->left), getHight(child->right));

    return child;
}

Node *insert(Node *root, int key)
{

    // doesn't exist
    if (!root)
        return new Node(key);

    // exist
    if (key < root->data) // left side
        root->left = insert(root->left, key);
    else if (key > root->data) // right side
        root->right = insert(root->right, key);
    else
        return root; // if equal

    // update the hight
    root->height = 1 + max(getHight(root->left), getHight(root->right));

    // check balancing
    int Blance = getBlanced(root);

    // unbalance

    // Left Left Side
    if (Blance > 1 && key < root->left->data)
        return rightRotation(root);

    // Right Right Side
    else if (Blance < -1 && key > root->right->data)
        return leftRotation(root);

    // Left Right Side
    else if (Blance > 1 && key > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // Right Left Side
    else if (Blance < -1 && key < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    // no unbalancing
    else
    {
        return root;
    }
}

void preOrder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (!root)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    // duplicate element are not allowed
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    cout << "PreOrder :";
    preOrder(root);
    cout << endl;

    cout << "inOrder :";
    inOrder(root);
    cout << endl;

    cout << "PostOrder :";
    postOrder(root);

    return 0;
}