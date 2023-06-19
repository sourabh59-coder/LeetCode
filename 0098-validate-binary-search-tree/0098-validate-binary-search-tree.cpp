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
    bool fun(TreeNode* root,long long maxv,long long minv)
    {
        if(root==NULL)  return true;
        
        if(root->val >= maxv || root->val <= minv)
        {
            return false;
        }
        
        return fun(root->right,maxv,root->val)&&fun(root->left,root->val,minv);
    }
    bool isValidBST(TreeNode* root) {
        return fun(root,LONG_MAX,LONG_MIN);
    }
};