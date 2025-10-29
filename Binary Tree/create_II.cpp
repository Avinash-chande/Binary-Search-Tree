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
Node *binary_tree()
{
    int x;
    cin >> x;
    if (x == -1)
        return NULL;
    Node *temp = new Node(x);
    // left
    cout << "enter the left child of " << x<<":";
    temp->left = binary_tree();

    // right
    cout << "enter the right child of " << x<<":";
    temp->right = binary_tree();
    // return address
    return temp;
}

int main()
{
    cout << "enter the root element :";
    Node *root;
    root = binary_tree();

    return 0;
}

/* enter the root element :1
enter the left child of 1:2
enter the root element :1
enter the left child of 1:2
enter the left child of 2:3
enter the left child of 1:2
enter the left child of 2:3
enter the left child of 3:4
enter the left child of 2:3
enter the left child of 3:4
enter the left child of 3:4
enter the left child of 4:-1
enter the left child of 4:-1
enter the right child of 4:-1
enter the right child of 3:5
enter the left child of 5:-1
enter the right child of 5:-1
enter the right child of 2:-1
enter the right child of 1:20
enter the left child of 20:-1
enter the right child of 20:-1  */

/*for this input we got the following tree stcture

                                    1

                          2                   20

                2-l:3       2-r:N   |    20-l:N       20-r:N

      4                 5

4-l:N   4-r:N | 5-l:N      5-R:N                                         */