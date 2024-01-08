class Solution {
    void calculateSum(TreeNode* root, int low, int high, int &sum) {
        if(root == NULL) return;
        if(root->val >= low && root->val <= high) sum += root->val;
        calculateSum(root->left, low, high, sum);
        calculateSum(root->right, low, high, sum);  
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        calculateSum(root, low, high, sum);
        return sum;
    }
};