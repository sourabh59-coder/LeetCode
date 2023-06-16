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
    void Fun(TreeNode* root, bool flag, vector<vector<int>> &ans)
    {
        if(root==NULL)  return;
        
        queue<TreeNode* > qe;
        qe.push(root);
        
        while(!qe.empty())
        {
            int size = qe.size();
            
            vector<int> v;
            v.clear();
            for(int i=0;i<size;i++)
            {
                TreeNode* node = qe.front();
                qe.pop();
                
                v.push_back(node->val);
                
                if(node->left)  qe.push(node->left);
                if(node->right) qe.push(node->right);
            }
            
            if(flag)
            {
                reverse(v.begin(),v.end());
                flag = false;
            }
            else
            {
                flag = true;
            }
            
            ans.push_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bool flag = false;
        
        Fun(root,flag,ans);
        
        return ans;
    }
};