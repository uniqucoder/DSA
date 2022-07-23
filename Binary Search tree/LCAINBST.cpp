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
        this->data = d;
        this->left = NULL;
        this ->right = NULL;
    }
};


Node* buildBST(Node* root, int data)
{
    //bases 
    if(root == NULL)
    {
        Node* newNode = new Node(data);
        return newNode;
    }

    if(data > root ->data)
    {
        root ->right = buildBST(root ->right, data);
    }
    else
    {
        root ->left = buildBST(root->left, data);
    }
}

void createBST(Node* &root)
{
    int data;
    cout<<"enter root node of BST"<<endl;
    cin>>data;

    while(data != -1)
    {
        root = buildBST(root,data);
        cout<<"Enter child node"<<endl;
        cin>>data;
    }
}

Node* LCA(Node* root, int n1,int n2)
{
    if(root == NULL)
        return NULL;
    
    if(root ->data < n1 && root ->data  < n2)
    {
        return LCA(root->right, n1, n2);
    }
    if(root ->data > n1 && root ->data > n2)
    {
        return LCA(root ->left,n1,n2);
    }

    return root;


}

int main()
{
    Node* root = NULL;

    createBST(root);

    cout<<endl;
    int n1,n2;
    cout<<"Enter value of n1"<<endl;
    cin>>n1;
    cout<<"Enter value of n2"<<endl;
    cin>>n2;
    cout<<LCA(root,n1,n2)->data<<endl;
    

}