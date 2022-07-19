

class Solution {
public:
    
    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        return max(height(root->left),height(root->right))+1;
    }
    
    int diameter(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int option1 = diameter(root ->left);
        int option2 = diameter(root ->right );
        
        int option3 = 1 + height(root->left) + height(root->right);
        
        return max(option1,max(option2,option3));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        return diameter(root)-1;
    }
};


//optimise
class Solution {
public:
    pair<int,int> diameter2(TreeNode* root) {
        
        if(root==NULL) {
            pair<int,int> p= make_pair(0,0);
            return p;
        }
        pair<int,int> left=diameter2(root->left);
        pair<int,int> right=diameter2(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second+1;
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
    
        return ans;
        }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int>ans = diameter2(root);
        return ans.first-1;
    }
};
