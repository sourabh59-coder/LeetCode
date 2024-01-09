class Solution {
public:
void solve(TreeNode* root,vector<int>&tree)
{
    if(root==NULL)
    {
        return ;
    }
    solve(root->left,tree);
    solve(root->right,tree);
    if(root->left == NULL && root->right == NULL)
    {
        cout<<root->val;
        tree.push_back(root->val);
    }

}


    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int>tree2;
        solve(root1,tree1);
        solve(root2,tree2);


        if(tree1==tree2)return true;
        else return false;

    }
};