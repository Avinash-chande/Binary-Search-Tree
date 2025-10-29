#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left, *right;

public:
    Node(int data)
    {
        val = data;
        left = right = NULL;
    }
};

Node *deleteBST(Node *root, int key)
{
    // base condtion
    if (!root)
        return NULL;

    if (root->val < key)
    {
        root->right = deleteBST(root->right, key);
        return root;
    }
    else if (root->val > key)
    {
        root->left = deleteBST(root->left, key);
        return root;
    }
    else
    {

        // leaf node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        
        // one child exist
        if (!root->right) // left child exist
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left) // right child exist
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // two child  exist
        else
        {
            // find gretest ele from left  ------>>>> one step left then extrem right
            Node *child = root->left;
            Node *parent = root;

            // right most node tak pauhachna hai
            while (child->right)
            {
                parent = child;
                child = child->right;
            }

            if (root != parent)
            {
                parent->right =child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else
            {
                child->right =root->right;
                delete root;
                return child;
            }
        }
    }
}
void inorder(Node* root){
    if (root != nullptr) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}


int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    int x = 15;

    root = deleteBST(root, x);
    inorder(root);
    return 0;


    return 0;
}