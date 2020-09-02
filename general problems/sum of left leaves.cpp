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
    int sum=0;
    unordered_map<int,int> mp;
    TreeNode* helper(TreeNode *root,int h)
    {
        if(root==NULL)
            return root;
        if(root->left)
        {
            root->left=helper(root->left,h+1);
            if(root->left->left==NULL&&root->left->right==NULL)
            {
               
                    sum+=root->left->val;
                
            }
        }
        if(root->right)
        {
            root->right=helper(root->right,h+1);
        }
        return root;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
        root=helper(root,0);
        return sum;
        
    }
};
