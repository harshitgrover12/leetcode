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
    bool helper(TreeNode *root,TreeNode *lower,TreeNode *upper)
    {
            if(root==NULL)
                return true;
        int val=root->val;
        if(lower!=NULL&&val<=lower->val)
            return false;
        if(upper!=NULL&&val>=upper->val)
            return false;
        if(!helper(root->left,lower,root))
            return false;
        if(!helper(root->right,root,upper))
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
    
  bool ans=helper(root,NULL,NULL);
      return ans;
   
    }
};

