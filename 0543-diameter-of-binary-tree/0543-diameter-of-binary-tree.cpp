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
    int fun(TreeNode* root,unordered_map<TreeNode*, int> &mp,int &ans)
    {
        if(root==NULL)  return 0;

        int lHeight = fun(root->left,mp,ans);
        int rHeight = fun(root->right,mp,ans);

        int he = max(lHeight,rHeight) + 1;
        mp[root] = he;

        ans = max(ans,lHeight+rHeight);

        return he;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode* , int> mp;
        int ans = 0;
        fun(root,mp,ans);
        return ans;
    }
};