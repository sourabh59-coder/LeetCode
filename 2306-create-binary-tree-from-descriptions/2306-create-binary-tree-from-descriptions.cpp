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
    TreeNode* createBinaryTree(vector<vector<int>>& v) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<int, TreeNode*> mp;

        int n = v.size();
        TreeNode* check = NULL;
        for(int i=0;i<n;i++)
        {
            TreeNode* ptr = new TreeNode(v[i][0]);
            TreeNode* child = new TreeNode(v[i][1]);
            int left = v[i][2];

            if(mp.count(ptr->val)!=0)   ptr = mp[ptr->val];
            else                        mp[ptr->val] = ptr;
            if(mp.count(child->val)!=0) child = mp[child->val];
            else                        mp[child->val] = child;
            
            check = ptr;
            if(parent.count(ptr)==0)    parent[ptr] = NULL;
            parent[child] = ptr;
            if(left)
            {
                ptr->left = child;
            }
            else
            {
                ptr->right = child;
            }
        }
        while(parent[check]!=NULL)
        {
            check = parent[check];
        }
        return check;
    }
};