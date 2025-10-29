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

// this is brute force approach  Time Complexicity is O(n) and Space COmplexicity O(h);
Node *insertion(Node *root, int key)
{

    // base condition
    if (root == NULL)
        return new Node(key);

    if (root->val == key)
        return root;

    // grater than root node
    if (root->val < key)
        root->right = insertion(root->right, key);

    // smaller than root node
    else
        root->left = insertion(root->left, key);

    return root;
}


//this is optimize approach TC O(h) and SC O(1)
Node *insert(Node *root, int key)
{
    Node *temp = new Node(key);

    if (root == NULL)
        return temp;

    Node *parent = NULL;
    Node *curr = root;
    while (curr != NULL)
    {
        parent = curr;

        if (curr->val < key)            //greater than root
            curr = curr->right;

        else if (curr->val > key)       //smaller than root
            curr = curr->left;

        else
            return root;            //equal to root
    }

    
    // If x is smaller, make it
    // left child, else right child
    if(parent->val>key)parent->left=temp;

    else parent->right=temp;
    
    return root;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}
int main()
{

    Node *root = new Node(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inOrder(root);

    return 0;
}