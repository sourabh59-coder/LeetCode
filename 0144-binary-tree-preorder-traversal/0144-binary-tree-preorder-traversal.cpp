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
    void PreOrderWithStack(TreeNode* root,vector<int> &ans)
    {
        stack< TreeNode * > st;
        
        if(root!=NULL)
        {
            st.push(root);
            
            while(!st.empty())
            {
                TreeNode* topv = st.top();
                st.pop();
                ans.push_back(topv->val);
                
                if(topv->right!=NULL)
                {
                    st.push(topv->right);
                }
                if(topv->left!=NULL)
                {
                    st.push(topv->left);
                }
            }
        }
    }
//     void PreOrderTraversal(TreeNode* root,vector<int> &ans)
//     {
//         if(root==NULL)  return;
        
//         ans.push_back(root->val);
        
//         PreOrderTraversal(root->left,ans);
        
//         PreOrderTraversal(root->right,ans);
//     }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        PreOrderWithStack(root,ans);
        
        return ans;
    }
};