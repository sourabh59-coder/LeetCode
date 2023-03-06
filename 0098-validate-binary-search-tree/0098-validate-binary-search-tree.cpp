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
    bool fun(TreeNode* root, long long max,long long min)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->val >= max || root->val <= min)
        {
            return false;
        }
        return fun(root->left,root->val,min)&&fun(root->right,max,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return fun(root,LONG_MAX,LONG_MIN);
    }
};