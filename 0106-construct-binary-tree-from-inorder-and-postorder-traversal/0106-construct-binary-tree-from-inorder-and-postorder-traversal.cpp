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
    TreeNode* fun(vector<int> &postorder,vector<int> &inorder,int ps,int pe,int is,int ie,map<int,int> &mp)
    {
        if(is>ie || ps>pe)  return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);
        int iRoot = mp[root->val];

        root->left = fun(postorder,inorder,ps,ps+iRoot-is-1,is,iRoot-1,mp);
        root->right = fun(postorder,inorder,ps+iRoot-is,pe-1,iRoot+1,ie,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)   mp[inorder[i]] = i;
        int ps = 0, is = 0, pe = n-1, ie = n-1;
        return fun(postorder,inorder,ps,pe,is,ie,mp);
    }
};