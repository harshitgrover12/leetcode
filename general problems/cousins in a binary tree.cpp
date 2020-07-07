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
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode *> q;
        q.push(root);
        map<int,int> height;
        map<int,TreeNode*>  parent;
        height[root->val]=0;
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left)
            {
                height[temp->left->val]=height[temp->val]+1;
                parent[temp->left->val]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                
                height[temp->right->val]=height[temp->val]+1;
                parent[temp->right->val]=temp;
                q.push(temp->right);
            }
        }
        if(height[x]==height[y]&&parent[x]!=parent[y])
            return true;
        else return false;
        
        
    }
};
