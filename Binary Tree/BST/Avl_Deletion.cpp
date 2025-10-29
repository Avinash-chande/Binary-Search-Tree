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
Node *deleteNode(Node *root, int key)
{

    // doesn't exist
    if (!root)
        return NULL;

    if (key < root->data) // left side
        root->left = deleteNode(root->left, key);
    else if (key > root->data) // right side
        root->right = deleteNode(root->right, key);
    else // root data  equal to key
    {
        // leaf node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        // one child exist
        else if (root->left && !root->right) // left child exist
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left && root->right) // rigth child exist
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // both child exist
        else
        {
            // one step right then go extrem left(find minimun value )
            Node *curr = root->right;
            while (curr->left)
            {
                curr = curr->left;
            }

            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }
    // update hight
    root->height = 1 + max(getHight(root->left), getHight(root->right));

    // check it is blance or not
    int blance = getBlanced(root);

    // left
    if (blance > 1)
    {
        // LL
        if (getBlanced(root->left) >= 0)
            return rightRotation(root);

        // LR
        else
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    // right
    if (blance < -1)
    {
        // RR
        if (getBlanced(root->right) <= 0)
            return leftRotation(root);
        // RL
        else
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
}

int main()
{

    return 0;
}