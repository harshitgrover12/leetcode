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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode *> q;
        q.push(root);
        map<TreeNode *,int> mp;
        mp[root]=1;
        map<int,int> cnt;
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            cnt[mp[temp]]+=temp->val;
            if(temp->left)
            {
                q.push(temp->left);
                mp[temp->left]=mp[temp]+1;
            }
            if(temp->right)
            {
                q.push(temp->right);
                mp[temp->right]=mp[temp]+1;
            }
        }
        int maxi=INT_MIN;
        int level=1;
        for(auto it:cnt)
            if(it.second>maxi)
            {
                level=it.first;
                maxi=it.second;
            }
        return level;
        
    }
};
