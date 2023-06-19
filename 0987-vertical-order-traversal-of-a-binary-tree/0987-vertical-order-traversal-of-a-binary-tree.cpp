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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)  return ans;
        map<int,map<int,multiset<int>>> mp;//v,l
        queue<pair<TreeNode* ,pair<int,int>>> qe;// node, v, l
        
        qe.push({root,{0,0}});
        
        while(!qe.empty())
        {
            auto top = qe.front();
            qe.pop();
            
            int x = top.second.first;
            int y = top.second.second;
            auto node = top.first;
            
            mp[x][y].insert(node->val);
            
            if(node->left)
            {
                qe.push({node->left,{x-1,y+1}});
            }
            
            if(node->right)
            {
                qe.push({node->right,{x+1,y+1}});
            }
        }
        
        for(auto p: mp)
        {
            vector<int> col;
            for(auto q: p.second)
            {
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};