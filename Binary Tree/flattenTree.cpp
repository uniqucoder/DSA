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

Node* flattenTree(Node* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    Node* curr = root;
    while(curr != NULL)
    {
        if(curr->left != NULL)
        {
            Node* pred = curr->left;
            while(pred->right!= NULL)
            {
                pred = pred ->right;
            }

            pred->right = curr ->right;
            curr->right = curr->left;
            curr->left = NULL;

        }
        curr= curr->right;
    }
    return root;
}

void printLL(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp ->data<<" ";
        temp= temp->right;
    }
}

int main()
{
    Node* root = buildTree();

    Node* head = flattenTree(root);

    printLL(head);
}