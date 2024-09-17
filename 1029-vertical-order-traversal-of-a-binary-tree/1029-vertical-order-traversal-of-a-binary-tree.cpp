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
        map<int,map<int,multiset<int>>> mp; // ver, level, data
        queue<pair<TreeNode*,pair<int,int>>> qe; // level, vertical
        vector<vector<int>> ans;
        if(root==NULL)  return ans;

        qe.push({root,{0,0}});

        while(!qe.empty())
        {
            auto it = qe.front();
            qe.pop();

            auto node = it.first;
            int level = it.second.first;
            int ver = it.second.second;

            mp[ver][level].insert(node->val);

            if(node->left)  qe.push({node->left,{level+1,ver-1}});
            if(node->right) qe.push({node->right,{level+1,ver+1}});
        }

        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            vector<int> vec;
            for(auto it1 = it->second.begin(); it1 != it->second.end(); it1++)
            {
                vec.insert(vec.end(), it1->second.begin(), it1->second.end());
            }
            ans.push_back(vec);
        }


        return ans;
    }
};