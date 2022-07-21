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
        this->data =d;
        this->left =NULL;
        this->right=NULL;
    }
};

Node* buildTree()
{
    int data;
    cout<<"Enter the value"<<endl;
    cin>>data;

    if(data == -1)
    {
        return NULL;
    }
    Node* root = new Node(data);
    root->left = buildTree();
    root->right= buildTree();

    return root;
}

void lvlOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* frontNode = q.front();
        q.pop();

        if(frontNode == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<frontNode->data<<" ";
            if(frontNode ->left != NULL)
            {
                q.push(frontNode->left);
            }
            if(frontNode->right != NULL)
            {
                q.push(frontNode->right);
            }
        }
    }
    
}
void inOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    
    //L 
    inOrderTraversal(root->left);
    //N 
    cout<<root->data<<" ";
    //R
    inOrderTraversal(root->right);
    

}

Node* getPredecessor(Node* root)
{
    if(root == NULL)
        return NULL;
    
    Node* temp = root->left;
    if(temp == NULL)
    {
        return NULL;
    }
    while(temp!=NULL)
    {
        temp = temp->right;
    }
    return temp;
}
int main()
{
    Node* root = buildTree();

    cout<<"Printing Lvl Order traversal"<<endl;
    lvlOrderTraversal(root);
    cout<<endl;
    cout<<"Printing Inorder traversal "<<endl;
    inOrderTraversal(root);
    cout<<endl;


    cout<<"Inorder predecessor "<<getPredecessor(root)->data<<endl;
}


// 3 5 2 -1 -1 7 -1 -1 5 -1 8  -1 -1