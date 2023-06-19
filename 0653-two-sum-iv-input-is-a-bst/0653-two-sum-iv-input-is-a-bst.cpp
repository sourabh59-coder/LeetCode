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
    void fun(TreeNode* root,int k,bool &ans,unordered_map<int,int> &mp)
    {
        if(root==NULL)  return;
        
        if(mp.find(k-(root->val))!=mp.end())
        {
            ans = true;
            return;
        }
        
        mp[(root->val)]++;
           
        fun(root->left,k,ans,mp);
           
        fun(root->right,k,ans,mp);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mp;
        bool ans = false;
        fun(root,k,ans,mp);
        return ans;
    }
};