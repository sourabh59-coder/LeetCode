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
    int Height(TreeNode* root)
    {
        if(root==NULL)  return -1;
        
        int lh = Height(root->left);
        int rh = Height(root->right);
        
        return (lh>rh) ? (lh+1) : (rh+1);
    }
    int maxDepth(TreeNode* root) {
        return Height(root)+1;
    }
};