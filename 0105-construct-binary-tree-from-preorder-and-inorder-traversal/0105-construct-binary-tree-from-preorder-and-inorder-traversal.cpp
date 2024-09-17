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
    TreeNode* fun(vector<int> &preorder,vector<int> &inorder,int is,int ie,int ps,int pe,map<int,int> &mp)
    {
        if(is>ie || ps>pe)  return NULL;
        
        TreeNode* root = new TreeNode(preorder[ps]);
        int iRoot = mp[root->val];


        root->left = fun(preorder,inorder,is,iRoot-1,ps+1,ps+iRoot-is,mp);
        root->right = fun(preorder,inorder,iRoot+1,ie,ps+iRoot-is+1,pe,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        int n = inorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }
        int is = 0, ps = 0, ie = n-1, pe = n-1;
        return fun(preorder,inorder,is,ie,ps,pe,mp);
    }
};