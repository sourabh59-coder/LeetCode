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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<TreeNode*> qe;
        if(root)    qe.push(root);

        while(!qe.empty())
        {
            auto it = qe.top();
            qe.pop();

            ans.push_back(it->val);

            if(it->right)  qe.push(it->right);

            if(it->left)  qe.push(it->left);
        }

        return ans;
    }
};