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

// Node* getPred(Node* curr)
// {
        
//     Node* temp = curr ->left;    
//     while(temp != NULL && temp->right != curr);
//     {
//         temp = temp ->right;
//     }
//     return temp;
        
// }

void inOrderMorriesTraversal(Node* root)
{
        Node* curr = root;
        
        while(curr != NULL)
        {
            if(curr ->left == NULL)
            {
                cout<<curr->data<<" ";
                curr = curr ->right;
            }
            else
            {
                Node* pred = curr->left;

                while (pred ->right != NULL && pred ->right != curr)    
                {
                    pred= pred->right;
                }
                
                
                //link crete
                if(pred->right == NULL)
                {
                    pred->right = curr;
                    curr = curr ->left;
                    
                }
                
                //remove link
                else
                {
                    pred ->right = NULL;
                    cout<<curr->data<<" ";
                    curr = curr->right;
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
int main()
{
    Node* root = buildTree();
    // cout<<"Inorder by recurssion"<<endl;
    // inOrderTraversal(root);
    cout<<endl;
    cout<<endl;
    cout<<"Inorder by morries"<<endl;
    inOrderMorriesTraversal(root);
    cout<<endl;
}