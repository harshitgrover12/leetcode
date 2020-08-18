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
class FindElements {
public:
    TreeNode* root1=NULL;
    bool helper1(TreeNode *root1,int target)
    {
        if(root1==NULL)
            return false;
        if(root1->val==target)
            return true;
        if(helper1(root1->left,target)||helper1(root1->right,target))
        {
            return true;
        }
        return false;
    }
    TreeNode* helper(TreeNode *root)
    {
        if(root==NULL)
            return root;
        if(root->left)
        {
            root->left->val=(root->val)*2+1;
            root->left=helper(root->left);
        }
        if(root->right)
        {
            root->right->val=(root->val)*2+2;
            root->right=helper(root->right);
        }
        return root;
    }
    FindElements(TreeNode* root) {
        
        root->val=0;
        root1=helper(root);
    }
    
    bool find(int target) {
        
            bool ans=helper1(root1,target);
        return ans;
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
