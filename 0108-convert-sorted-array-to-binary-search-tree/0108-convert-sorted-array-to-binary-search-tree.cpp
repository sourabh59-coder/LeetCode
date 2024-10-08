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
    TreeNode* fun(vector<int> &v,int l,int r)
    {
        if(l>r) return NULL;
        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(v[mid]);

        root->left = fun(v,l,mid-1);
        root->right = fun(v,mid+1,r);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n-1;
        return fun(v,l,r);
    }
};