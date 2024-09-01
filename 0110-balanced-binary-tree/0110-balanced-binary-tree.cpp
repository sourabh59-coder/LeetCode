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
    int fun(TreeNode* root,bool &ans)
    {
        if(root==NULL)  return 0;

        int l = fun(root->left,ans);
        int r = fun(root->right,ans);

        if(abs(r-l)>1)  ans = false;

        return max(l,r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        fun(root,ans);
        return ans;
    }
};