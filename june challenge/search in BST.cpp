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
    TreeNode *temp=NULL;
    TreeNode *searchi(TreeNode *root,int val)
    {
        if(root==NULL)
            return NULL;
        if(root->val==val)
        {
            temp=root;
         return root;
        }
        
        
        if(root->val<val)
        {
            root->right=searchi(root->right,val);
        }
        else if(root->val>val)
            root->left=searchi(root->left,val);
          
            return root;
        
    }
    TreeNode* searchBST(TreeNode* root, int val) {

        root=searchi(root,val);
        return temp;
        
        
    }
};
