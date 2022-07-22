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



// inorder se O(1) space mein
int currMax = INT_MIN;
bool inorderBStCheck(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    if(root ->data < currMax)
    {
        currMax = root->data;
        return true;
    }
    else
    {
        return false;
    }

    bool leftAns = inorderBStCheck(root ->left);
    bool rightAns = inorderBStCheck(root->right);

    return leftAns && rightAns;

}


int main()
{
    Node* root = NULL;

    createBST(root);

    // approch 1 using vector
    // vector<int>ans;

    // inorder(root, ans);

    // cout<< isBST(root, ans)<<endl;
}