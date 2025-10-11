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
void sum(Node *root ,int cnt)
{
    if (root == NULL)
        return;

    cnt++;
    sum(root->left, cnt);
    sum(root->right, cnt);

    cout<< "height is :"<<cnt<<endl;
}

int main()
{
    cout << "enter the root element :";
    Node *root;
    root = binary_tree();
    sum(root ,0);
   
    return 0;
}