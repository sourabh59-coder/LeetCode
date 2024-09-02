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
    TreeNode* fun(unordered_map<int,int> &mp,vector<int> &preorder,int ps,int pe,vector<int> &inorder,int is,int ie)
    {
        if(ps>pe || is>ie)  return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);
        int inRoot = mp[preorder[ps]];
        // int cnt = 

        root->left = fun(mp,preorder,ps+1,ps+inRoot-is,inorder,is,inRoot-1 );

        root->right = fun(mp,preorder,ps+inRoot-is+1,pe,inorder,inRoot+1,ie);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }
        return fun(mp,preorder,0,n-1,inorder,0,n-1);
    }
};