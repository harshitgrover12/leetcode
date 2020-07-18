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
#define ll long long 
class Solution {
public:
   long long int modulo=pow(10,9)+7;
vector<int> fi;
    
   ll total_sum(TreeNode *root)
    {   
        if(root==NULL)
        {
            return 0;
        }
        ll ans=root->val+total_sum(root->left)+total_sum(root->right);
       fi.push_back(ans);
        return ans;
    
    }
   
    ll maxProduct(TreeNode* root) {
        ll sum=total_sum(root);
        ll maxi=INT_MIN;
       for(int i=0;i<fi.size();i++)
       {
            maxi=max(maxi,((sum-fi[i])*fi[i]));
       }
        return maxi%modulo;
        
    }
};
