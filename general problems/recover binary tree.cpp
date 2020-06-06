/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sindex=-1;
    int eindex=-1;
    vector<int> a;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
            a.push_back(root->val);
        
        inorder(root->right);
    }
    void findindex()
    {
        for(int i=0;i<a.size()-1;i++)
        {
            if(a[i]>a[i+1]&&sindex==-1)
            {
                sindex=i;
            }
             else if(a[i]>a[i+1]&&sindex!=-1)
            {
                eindex=i+1;
            }
        }
        if(eindex==-1)
            eindex=sindex+1;
    }
    void setTreeRight(TreeNode *root)
    {
     if(root==NULL)
         return ;
        setTreeRight(root->left);
        if(root->val==a[sindex])
            root->val=a[eindex];
        else if(root->val==a[eindex])
            root->val=a[sindex];
        setTreeRight(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        findindex();
        setTreeRight(root);
        
    }
};
