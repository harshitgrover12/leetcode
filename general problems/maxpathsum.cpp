/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 int max_sum = INT_MIN;
 int global_ans = INT_MIN;
 
 int check(TreeNode* root)
 {
     if(root==NULL)
      return 0 ;
      
     int l1 = check(root->left);
     int r1 = check(root->right);
     
     
     int ans = root->val;
                        
   
          ans  =  max(ans,max(root->val+ l1,root->val+r1));
         max_sum  = max(max_sum , max(l1+r1+root->val,ans)) ;
       
         
        //  cout<<ans<<endl;
         return ans ;
 }
int Solution::maxPathSum(TreeNode* root) 
{
      
      if(root==NULL)
         return 0 ;
         
         
         int x = check(root);
         int x1=max_sum;
         max_sum=INT_MIN;
         return x1;
     
     
    
}
//9 -200 -100 -1 -300 -400 -1 -1 -1 -1
//https://www.linkedin.com/in/harshit-grover-448a0217b/
