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
    bool Fun(TreeNode* l,TreeNode* r)
    {
        if(l==NULL && r==NULL)  return true;
        
        if(l==NULL && r!=NULL)  return false;
        
        if(l!=NULL && r==NULL)  return false;
        
        return (r->val==l->val)&&(Fun(l->right,r->left))&&(Fun(l->left,r->right));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)  return true;
        
        return Fun(root->left,root->right);
    }
};