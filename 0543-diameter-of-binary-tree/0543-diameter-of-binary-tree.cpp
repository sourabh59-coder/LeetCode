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
    int Height(TreeNode* root, int &ans)
    {
        if(root==NULL)  return -1;
        
        int lh = Height(root->left,ans);
        int rh = Height(root->right,ans);
        
        int hei = max(lh,rh)+1;
        
        ans = max(ans,lh+rh+1);
        
        return hei;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        Height(root,ans);
        return ans+1;
    }
};