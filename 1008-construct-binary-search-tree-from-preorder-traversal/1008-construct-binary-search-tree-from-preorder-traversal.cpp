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
    int ind = 0;
    TreeNode* Fun(vector<int> v,int ub)
    {
        if(v.size()==ind || v[ind]>ub)  return NULL;
        
        TreeNode* root = new TreeNode(v[ind++]);
        
        root->left = Fun(v,root->val);
        
        root->right = Fun(v,ub);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return Fun(preorder,INT_MAX);
    }
};