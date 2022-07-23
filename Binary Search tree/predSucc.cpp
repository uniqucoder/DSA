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

pair<int,int> predSuccBST(Node* root, int key)
{
    int pred=-1, succ = -1;

    if(root == NULL)
    {
        return make_pair(pred,succ);
    }

    //find key
    Node* temp = root;
    while(temp->data != key)
    {
        if(key > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp ->left;
        }
    }

    Node* p = temp->left;
    while(p->right != NULL)
    {
        p = p ->right;
    }
    pred= p->data;
    Node* s = temp ->right;
    while (s ->left != NULL)
    {
        s = s->left;
    }
    succ = s ->data;

    return make_pair(pred,succ);
    


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

int main()
{
    Node* root = NULL;

    createBST(root);

    cout<<endl;

    int key;

    cout<<"Enter Key"<<endl;
    cin>>key;
    pair<int,int> ans = predSuccBST(root, key);

    cout<<"Pred is : "<<ans.first<<"second "<<ans.second<<endl;

}