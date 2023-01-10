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

void Solve(TreeNode* p,TreeNode* q,bool &ans)
{
    if(p==NULL && q==NULL)
    {
        return;
    }
    if(p==NULL || q==NULL)
    {
        ans = false;
        return;
    }
    
    if(p->val==q->val)
    {
        Solve(p->left,q->left,ans);
        Solve(p->right,q->right,ans);
    }
    else
    {
        ans = false;
        return;
    }
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true;
        
        Solve(p,q,ans);
        
        return ans;
    }
};