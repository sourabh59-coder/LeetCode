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
    void InorderWithStack(TreeNode* r,vector<int> &ans)
    {
        stack<TreeNode * > st;
        
        while(true)
        {
            if(r!=NULL)
            {
                st.push(r);
                r = r->left;
            }
            else
            {
                if(st.empty())
                {
                    break;
                }
                
                r = st.top();
                st.pop();
                
                ans.push_back(r->val);
                r = r->right;
            }
        }
    }
//     void InorderTraversal(TreeNode* root,vector<int> &ans)
//     {
//         if(root==NULL)  return;
        
//         InorderTraversal(root->left,ans);
        
//         ans.push_back(root->val);
        
//         InorderTraversal(root->right,ans);
        
//     }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        InorderWithStack(root,ans);
        
        return ans;
    }
};