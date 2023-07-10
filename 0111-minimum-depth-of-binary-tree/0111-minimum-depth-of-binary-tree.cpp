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
    int fun(TreeNode* root)
    {
        if(root==NULL)  return 0;
        queue<TreeNode* > qe;
        qe.push(root);
        int lev = 0;
        
        while(!qe.empty())
        {
            int size = qe.size();
            lev++;
            for(int i=0;i<size;i++)
            {
                auto node = qe.front();
                qe.pop();
                
                if(node->left)    qe.push(node->left);
                if(node->right)    qe.push(node->right);
                
                if(!node->left && !node->right) return lev;
            }
        }
        
        return -1;
    }
    int minDepth(TreeNode* root) {
        return fun(root);
    }
};