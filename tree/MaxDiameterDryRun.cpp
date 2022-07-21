#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;

    }
};

Node* buildTree()
{
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    if(data == -1 )
    {
        return NULL;
    }

    Node* newNode = new Node(data);

    //left sub tree
    newNode ->left = buildTree();

    //right subtree
    newNode ->right = buildTree();

    return newNode;

}

void lvlOrderTraversal(Node* root)
{
    queue<Node*>q;
    q.push(root);

    q.push(NULL);
    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();

        if(front == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<front->data<<" ";

            if(front->left != NULL)
                q.push(front->left);
            
            if(front ->right != NULL)
            {
                q.push(front ->right);
            }
        }

        
    }
}

Node* BuildTreeLvlOrder()
{
    queue<Node*>q;
    int data;
    cout<<"Enter the root node"<<endl;
    cin>>data;
    Node* root = new Node(data);
    q.push(root);

    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();
        
        // left add
        cout<<"Enter node of left of "<<front->data <<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1)
        {
            front ->left = new Node(leftdata);
        }

        //Right add
        cout<<"Enter node of Right of "<<front->data <<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1)
        {
            front ->left = new Node(rightData);
        }

    }
}
int main()
{
    Node* root = buildTree();

    //Level Order treversal

    BuildTreeLvlOrder();

    lvlOrderTraversal(root);

    return 0;

}

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
// 1 2 3 4 5 6 7 