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
    int cnt=0;
    void helper(TreeNode *root,int c)
    {
        if(root==NULL)
            return;
            if(root->left==NULL&&root->right==NULL)
            {
                cnt+=c*10+root->val;
                return;
            }
        helper(root->left,c*10+root->val);
        helper(root->right,c*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        helper(root,0);
        return cnt;
        
    }
};
