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
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int height=0;
        TreeNode *leftNode,*rightNode=root;
        while(rightNode!=NULL)
        {
            height++;
            leftNode=leftNode->left;
            rightNode=rightNode->right;
        }
        if(leftNode==NULL)
            return (1<<height)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};
