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
    TreeNode* fun(unordered_map<int,int> &mp,vector<int> &postorder,int ps,int pe,vector<int> &inorder,int is,int ie)
    {
        if(is>ie || ps>pe)  return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int inRoot =  mp[root->val];

        root->right = fun(mp,postorder,ps+inRoot-is,pe-1,inorder,inRoot+1,ie);

        root->left = fun(mp,postorder,ps,ps+inRoot-is-1,inorder,is,inRoot-1); 

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n==0)    return NULL;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }
        return fun(mp,postorder,0,n-1,inorder,0,n-1);
    }
};