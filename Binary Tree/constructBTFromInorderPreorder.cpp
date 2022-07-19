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
        this->right = NULL;
    }
};

Node* buildTree()
{
    cout<<"Enter elements of tree"<<endl;
    int data;
    cin>>data;
    if(data == -1)
    {

        return NULL;
    }
    Node* newNode = new Node(data);
    cout<<"Enter LEFT Child of Node"<<newNode->data<<endl;
    newNode->left = buildTree();
    cout<<"Enter right Child of Node"<<newNode->data<<endl;
    newNode->right = buildTree();

    return newNode;

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

int position(vector<int>in,int key, int s, int e)
{
    for(int i=s;i<=e;i++)
    {
        if(in[i] == key)
        {
            return i;
        }
    }
    return -1;
}

Node* buildTreeInorderPreorder(vector<int>in, vector<int>pre, int &preOrderIndex,int inStart, int inEnd)
{
    if(preOrderIndex >= pre.size() || inStart > inEnd)
    {
        return NULL;
    }

    //take first element of preorder as root node
    int element = pre[preOrderIndex++];
    Node * root = new Node(element);
    int pos = position(in,element, inStart,inEnd);

    root->left = buildTreeInorderPreorder(in,pre,preOrderIndex,inStart,pos-1);
    root->right = buildTreeInorderPreorder(in,pre,preOrderIndex,pos+1,inEnd);

    return root;
}
int main()
{
    // Node* root = buildTree();

    vector<int>in={4,2,5,1,6,3,7};
    vector<int>pre={1,2,4,5,3,6,7};
    int index=0;
    Node* root = buildTreeInorderPreorder(in,pre,index,0,in.size());

    lvlOrderTraversal(root);
}