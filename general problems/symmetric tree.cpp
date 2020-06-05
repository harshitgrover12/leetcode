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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        map<int,vector<TreeNode*>> mp;
        map<TreeNode*,int> m;
        m[root]=0;
        mp[0].push_back(root);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(!temp)
                continue;
            
                q.push(temp->left);
                mp[m[temp]+1].push_back(temp->left);
                m[temp->left]=m[temp]+1;
            
           
            
                q.push(temp->right);
                mp[m[temp]+1].push_back(temp->right);
                m[temp->right]=m[temp]+1;
            
        }
          map<int,vector<TreeNode*>>::iterator it;
          for(it=mp.begin();it!=mp.end();it++)
          {
              int i=0;
              int j=it->second.size()-1;
              while(i<j)
              {
                  if(it->second[i]&&it->second[j])
                  {
                  if(it->second[i]->val!=it->second[j]->val)
                      return false;
                      
                  }
                  else if(it->second[i]||it->second[j])
                      return false;
                     
                  i++;
                  j--;
                 
              }
          }
          return true;
        
        
        
    }
};
