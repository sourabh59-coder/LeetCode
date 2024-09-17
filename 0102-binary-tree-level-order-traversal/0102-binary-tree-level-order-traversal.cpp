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
        vector<int> temp;
        if(root==NULL)  return ans;
        queue<TreeNode*> qe;
        qe.push(root);

        while(!qe.empty())
        {
            int si = qe.size();
            vector<int> temp;

            for(int sp=0;sp<si;sp++)
            {
                auto it = qe.front();
                qe.pop();

                temp.push_back(it->val);
                if(it->left)    qe.push(it->left);
                if(it->right)   qe.push(it->right);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};