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
    int rightHeight(TreeNode* root)
    {
        int ans = 0;
        while(root!=NULL)
        {
            ans++;
            root = root->right;
        }
        return ans;
    }
    int leftHeight(TreeNode* root)
    {
        int ans = 0;
        while(root)
        {
            ans++;
            root = root->left;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)  return 0;
        int l = leftHeight(root->left);
        int r = rightHeight(root->right);
        if(l==r)    return pow(2,l+1) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};