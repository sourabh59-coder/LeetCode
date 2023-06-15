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
    void Par(TreeNode* root,vector<int> &depth , vector<int> &parent)
    {
        if(root==NULL)  return;
        
        if(root->left)
        {
            parent[root->left->val] = root->val;
            depth[root->left->val] = depth[root->val]+1;
            Par(root->left,depth,parent);
        }
        
        if(root->right)
        {
            parent[root->right->val] = root->val;
            depth[root->right->val] = depth[root->val]+1;
            Par(root->right,depth,parent);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> depth(1000,0);
        vector<int> parent(1000,-1);
        Par(root,depth,parent);
        // for(int i=0;i<10;i++)
        // {
        //     cout<<i<<" "<<depth[i]<<" "<<parent[i]<<endl;
        // }
        return(parent[x]!=parent[y] && depth[x]==depth[y]);
    }
};