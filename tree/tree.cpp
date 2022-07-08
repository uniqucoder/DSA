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
    cout<<"Enter the value of data for "<<endl;

    int data ;
    cin>>data;

    //base case 
    if(data == -1)
    {
        return NULL;
    }
    Node* newNode = new Node(data);

    //left 
    cout<<"Checking left child"<<data <<endl;
    
    newNode ->left = buildTree();
    //right
    cout<<"checking right child "<<data <<endl;
    
    newNode ->right = buildTree();

    return newNode;

}


//PReOrder traversal

void preOrder(Node* &root)
{
    //base case
    if(root == NULL)
    {
        return;
    }

    //N
    cout<<root->data<<" ";
    //L
    preOrder(root->left);

    //R
    preOrder(root->right);
}

//PReOrder traversal

void inOrder(Node* &root)
{
    //base case
    if(root == NULL)
    {
        return;
    }
    //L
    inOrder(root->left);
    //N
    cout<<root->data<<" ";
    

    //R
    inOrder(root->right);
}

//Post order traversal 
void postOrder(Node* &root)
{
    //base case
    if(root == NULL)
    {
        return;
    }
    //L
    postOrder(root->left);
    //N
    cout<<root->data<<" ";
    

    //R 
    postOrder(root->right);
}


//lvlOrderTraversal
void lvlOrderTraversal(Node* &root)
{
    queue<Node*> q;

    q.push(root);
    q.push(NULL);
    while (!q.empty())
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
            //add childs to queue

            if(front->left != NULL)
            {
                q.push(front->left);
            }
            if(front->right != NULL)
            {
                q.push(front ->right);
            }
        }


        
    }
    
}


int main()
{
    Node* root = buildTree();

    //preorder traversal

    cout<<"Preorder traversal"<<endl;
    preOrder(root);
    cout<<endl;

    //preorder traversal

    cout<<"inorder traversal"<<endl;
    inOrder(root);
    cout<<endl;

    //post ordertraversal

    cout<<"Post order treaversal"<<endl;
    postOrder(root);
    cout<<endl;

    //level order traversal

    cout<<"Level Order traversal"<<endl;
    lvlOrderTraversal(root);
    cout<<endl;




}


//10 5 3 -1 -1 7 6 -1 -1 -1 11 -1 -1
