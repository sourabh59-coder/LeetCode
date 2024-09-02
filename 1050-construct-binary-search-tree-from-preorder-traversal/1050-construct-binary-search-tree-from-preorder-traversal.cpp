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
    TreeNode* fun(unordered_map<int,int> &mp,vector<int> &inorder,int is,int ie,vector<int> &preorder,int ps,int pe)
    {
        if(is>ie || ps>pe)  return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);

        int inRoot = mp[root->val];

        root->right = fun(mp,inorder,inRoot+1,ie,preorder,ps+inRoot-is+1,pe);

        root->left = fun(mp,inorder,is,inRoot-1,preorder,ps+1,ps+inRoot-is);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        int n = preorder.size();
        for(auto it:preorder)   inorder.push_back(it);
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)    mp[inorder[i]] = i;
        return fun(mp,inorder,0,n-1,preorder,0,n-1);
    }
};