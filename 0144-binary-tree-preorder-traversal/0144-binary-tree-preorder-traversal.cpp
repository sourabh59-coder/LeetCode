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
    void PreOrderTraversal(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)  return;
        
        ans.push_back(root->val);
        
        PreOrderTraversal(root->left,ans);
        
        PreOrderTraversal(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        PreOrderTraversal(root,ans);
        
        return ans;
    }
};