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
        this ->data = d;
        this->left = NULL;
        this->right = NULL;

    }

};


Node* buildBST(Node* root , int data)
{
    if(root == NULL)
    {
        Node* temp = new Node(data);
        return temp;
    }

    if(data > root->data)
    {
        root ->right = buildBST(root ->right, data);
    }
    else
    {
        root ->left = buildBST(root ->left,data);
    }

    return root;
}

void createBST(Node* &root)
{
    int data;
    cout<<"Enter root node of BST"<<endl;
    cin>>data;

    while(data != -1)
    {
        root= buildBST(root,data);
        cin>>data;

    }
}

void lvlOrdertraversal(Node* root)
{
    if(root == NULL)
        return ;

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
            cout<<front ->data<<" ";

            if(front ->left != NULL)
                q.push(front ->left);
            if(front ->right != NULL)
                q.push(front ->right);

        }
    }
    
    

}


void inorder(Node* root , vector<int>&in)
{
    if(root == NULL)
        return;
    
    inorder(root ->left,in);
    in.push_back(root->data);
    inorder(root ->right,in);

}


void solve(Node* &root , vector<int>&in, int &i)
{
    if(root == NULL)
        return;
    
    root ->data = in[i++];
    solve(root ->left,in,i);
    solve(root->right,in,i);
}

Node* convertBSTToMinHeap(Node* &root)
{
    vector<int>in;

    inorder(root,in);
    for(auto &i : in)   
    {
        cout<<i<<" ";
    }cout<<endl;
    int i =0;
    solve(root,in,i);

    return root;
}

int main()
{
    Node* root = NULL;

    createBST(root);

    lvlOrdertraversal(root);

    cout<<endl;
    cout<<endl;


    convertBSTToMinHeap(root);

    lvlOrdertraversal(root);


    cout<<endl;
    cout<<endl;

}