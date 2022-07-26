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
        this->right =NULL;
    }
};

Node* buildBST(Node* root, int data)
{
    if(root == NULL)
    {
        Node* temp = new Node(data);
        return temp;
    }

    if(data > root ->data)
    {
        root->right = buildBST(root ->right, data);
    }
    else
    {
        root ->left = buildBST(root ->left,data);
    }
}


//Approch 1:

void inorder(Node* root, vector<int>&ans)
{
    if(root == NULL)
        return;

    //l
    inorder(root->left,ans);
    //N
    ans.push_back(root ->data);
    //r
    inorder(root->right, ans);
}

bool isBST(Node* root, vector<int>ans)
{
    for(int i=0;i<ans.size()-1;i++)
    {
        if(ans[i] > ans[i+1] )
        {
            return false;
        }
    }

    return true;
}
void createBST(Node* &root )
{
    cout<<"Enter root node of BST"<<endl;
    int data;
    cin>>data;

    while (data != -1)
    {
        root = buildBST(root, data);
        cout<<"Enter child nodes"<<endl;
        cin>>data;
    }
    
}
void lvlOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;

    }
    queue<Node*> q;
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
            if(frontNode->left != NULL)
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

Node* inorderToBST(int s, int e, vector<int>&in)
{
    if(s >e)
        return NULL;

    
    int mid = (s +e) /2;

    Node* newNode = new Node(in[mid]);

    newNode->left = inorderToBST(s,mid-1,in);
    newNode->right = inorderToBST(mid+1,e,in);

    return newNode;
}
int main()
{
    Node* root = NULL;

    createBST(root);

    lvlOrderTraversal(root);
    cout<<endl;
    vector<int>in;
    inorder(root, in);

    int s =0;
    int e = in.size()-1;
    Node* root1 = inorderToBST(s,e,in);

    
    lvlOrderTraversal(root1);
    
    cout<<endl;
}