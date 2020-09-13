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
    void helper(TreeNode *root,int sum,unordered_map<int,int> mp,int &cnt,int cur)
    {
   
        if(root==NULL)
            return;
    int temp=cur+root->val;
        int diff=temp-sum;
        if(mp[diff]>0)
            cnt+=mp[diff];
        mp[temp]++;
        helper(root->left,sum,mp,cnt,temp);
         helper(root->right,sum,mp,cnt,temp);
        mp[temp]--;
        
    }
    int pathSum(TreeNode* root, int sum) {
        
       unordered_map<int,int> mp;
        int cnt=0;
        mp[0]++;
        helper(root,sum,mp,cnt,0);
        return cnt;
        
    }
};
