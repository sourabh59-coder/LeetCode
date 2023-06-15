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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue<TreeNode* > qe;
        
        if(root!=NULL)  qe.push(root);
        
        while(!qe.empty())
        {
            vector<int> v;
            v.clear();
            int size = qe.size();
            
            for(int i=0;i<size;i++)
            {
                auto node = qe.front();
                qe.pop();
                v.push_back(node->val);
                
                if(node->left)
                {
                    qe.push(node->left);
                }
                
                if(node->right)
                {
                    qe.push(node->right);
                }
            }
            
            ans.push_back(v);
        }
        
        return ans;
    }
};