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
} ;
int main()
{
    int x;
    cout<<"enter the root value :";
    cin>>x;
    int first ,sec ;

    queue<Node*>q;          //it store the add of node(given val)
    Node*root =new Node(x);
    q.push(root);           //push into queue 

    while (!q.empty())
    {
        Node*temp =q.front();  //create temp and store into q's first value
        q.pop();

        //left child ele
        cout<<"Enter the left child ele :"<<temp->data<<":-";
        cin>>first;
        if(first!=-1){
            temp->left =new Node(first);
            q.push(temp->left);
        }

        //right child ele
        cout<<"Enter the right child ele :"<<temp->data<<":-";
        cin>>sec;
        if(sec!=-1){
            temp->right =new Node(sec);
            q.push(temp->right);
        }

    }
    return 0;
}

/*your input like this '1,2,3,4,-1,5,6,-1,9'
 output got like this :
 
                     1
            2              3
        4     NULL     5      6
    NULL      9                      */