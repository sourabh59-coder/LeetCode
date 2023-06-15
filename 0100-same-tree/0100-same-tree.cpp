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
    bool Helper(TreeNode* p,TreeNode* q)
    {
        if(p==NULL && q==NULL)  return true;
        
        if(p==NULL && q!=NULL)  return false;
        
        else if(p!=NULL && q==NULL) return false;
        
        else
        {
            bool a = Helper(p->left,q->left);
            bool b = Helper(p->right,q->right);
            
            return (a&&b&&(p->val==q->val));
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return Helper(p,q);
    }
};