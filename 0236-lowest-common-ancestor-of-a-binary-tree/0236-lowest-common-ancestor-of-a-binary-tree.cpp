/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Function(TreeNode* root,unordered_map<TreeNode* , TreeNode* > &mp,TreeNode* parent)
    {
        if(root==NULL)  return;
        
        mp[root] = parent;
        
        Function(root->left,mp,root);
        Function(root->right,mp,root);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode* , TreeNode* > mp;
        
        Function(root,mp,NULL);
        
        vector<TreeNode* > pv,qv;
        
        while(p!=NULL)
        {
            pv.push_back(p);
            p = mp[p];
        }
        
        while(q!=NULL)
        {
            qv.push_back(q);
            q = mp[q];
        }
        
        reverse(qv.begin(),qv.end());
        reverse(pv.begin(),pv.end());
        
        // for(int i=0;i<qv.size();i++)
        // {
        //     cout<<qv[i]->val<<endl;
        // }
        
        TreeNode* ans = NULL;
        for(int i=0;i<qv.size() && i<pv.size();i++)
        {
            // cout<<qv[i]->val<<" "<<pv[i]->val<<endl;
            if(qv[i]->val==pv[i]->val)
            {
                ans = qv[i];
            }
            // else
            // {
            //     break;
            // }
        }
        return ans;
    }
};