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
    int maxLevelSum(TreeNode* root) {
        int ans = INT_MIN;
        int var = 0;
        
        queue<TreeNode* > qe;
        qe.push(root);
        int lev = 0;
        
        while(!qe.empty())
        {
            lev++;
            int size = qe.size();
            int sum = 0;
            
            for(int i=0;i<size;i++)
            {
                TreeNode* frontV = qe.front();
                sum += frontV->val;
                qe.pop();
                
                if(frontV->left)
                {
                    qe.push(frontV->left);
                }
                
                if(frontV->right)
                {
                    qe.push(frontV->right);
                }
            }
            
            if(sum>ans)
            {
                ans = sum;
                var = lev;
            }
        }
        
        return var;
    }
};