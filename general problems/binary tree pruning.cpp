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
    bool check(TreeNode *root)
    {
        if(root==NULL)
            return false;
        if(root->val==1)
            return true;
        if(check(root->left)||check(root->right))
            return true;
        return false;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)
            return root;
        if(root->val==0)
        {
                bool ans1=check(root->left);
                bool ans2=check(root->right);
            if(!ans1&&!ans2)
                return NULL;
            if(!ans1)
                root->left=NULL;
            if(!ans2)
                root->right=NULL;
        }
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        return root;
    }
};
