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
#define ll long long
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue <ll, vector<ll>, greater<ll>> gq;
        
        queue<TreeNode* > qe;
        
        qe.push(root);
        
        while(!qe.empty())
        {
            ll sum = 0;
            ll size = qe.size();
            
            
            for(int i=0;i<size;i++)
            {
                TreeNode* node = qe.front();
                qe.pop();
                sum += node->val;
                
                if(node->left)  qe.push(node->left);
                
                if(node->right) qe.push(node->right);
            }
            
            gq.push(sum);
            if(gq.size()>k)
            {
                gq.pop();
            }
        }
        
        return (gq.size()==k) ? gq.top() : -1;
    }
};