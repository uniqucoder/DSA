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

Node* buildBST(Node* root, int data)
{
    if(root == NULL)
    {
        Node* temp = new Node(data);
        return temp;
    }

    if(data  > root->data)
    {
        root->right = buildBST(root->right,data);
    }
    else
    {
        root ->left = buildBST(root->left,data);
    }
    
}

void createBST(Node* &root)
{
    cout<<"Enter The root node of BST"<<endl;
    int data;
    cin>>data;
    while (data != -1)
    {
        root = buildBST(root,data);
        cout<<"Enter child data"<<endl;
        cin>>data;
    }
    
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

void preOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    //N 
    cout<<root->data<<" ";
    //L 
    preOrderTraversal(root->left);
    //R
    preOrderTraversal(root->right);

}

void postOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    
    //L 
    postOrderTraversal(root->left);
    //R
    postOrderTraversal(root->right);
    //N 
    cout<<root->data<<" ";

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

int minValueInBST(Node* root)
{
    Node* temp=root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }


    return temp->data;
    
}

int maxValueInBST(Node* root)
{
    Node* temp = root;
    while(temp ->right != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

bool search(Node* root, int target)
{
    if(root == NULL)
        return false;
    if(root->data == target)
    {
        return true;
    }
    if(target < root ->data)
    { 
        bool leftAns = search(root->left,target);
        if(leftAns == true)
            return true;
    }
    else
    {
        bool rightAns = search(root->right,target);
        if(rightAns == true)
            return true;
    }

    return false;

}

Node* maxValue(Node* root)
{
    Node* temp = root;
    while (temp->right != NULL)
    {
        temp = temp ->right;
    }
    return temp;
    
}

Node* deleteNode(Node* root, int target)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == target)
    {
        //0 child
        if(root->left == NULL && root ->right == NULL)
        {
            delete root;
            return NULL;
        }
        //1 child
        if(root ->left != NULL && root ->right == NULL)
        {
            Node* temp = root ->left;
            delete root;
            return temp;
        }
        if(root ->left == NULL && root ->right != NULL)
        {
            Node* temp = root ->right;
            delete root;
            return temp;
        }

        //2 child
        if(root ->left != NULL && root ->right != NULL)
        {
            //pred nikalo
            int pred = maxValue(root->left)->data;

            //root ke data ke sath replace kr do
            root->data = pred;

            root->left = deleteNode(root->left,pred);

            return root;

        }


    }
    else if(target  > root ->data)
    {
        root ->right = deleteNode(root->right,target);
    }
    else
    {
        root->left = deleteNode(root->left,target);
    }
}

int main()
{
    Node* root = NULL;

    createBST(root);
    cout<<"Printing Lvl order traversal "<<endl;
    lvlOrderTraversal(root);
    cout<<endl;
    // cout<<"Printing Preorder traversal"<<endl;
    // preOrderTraversal(root);
    // cout<<endl;
    // cout<<"Printing inOrder traversal"<<endl;
    // inOrderTraversal(root);
    // cout<<endl;
    // cout<<"Printing Post Order traversal"<<endl;
    // postOrderTraversal(root);

    cout<<endl;

    int target;
    cout<<"Enter target to Delete From BSt"<<endl;
    cin>>target;
    // cout<<"Search In BST "<<search(root, target);


    root = deleteNode(root,target);

    lvlOrderTraversal(root);

}
