class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        queue<pair<TreeNode*, unsigned long long>> qe; 
        qe.push({root, 0});
        int maxWidth = 0;
        
        while (!qe.empty()) {
            int size = qe.size();
            unsigned long long minIndex = qe.front().second; 
            unsigned long long first, last;
            
            for (int i = 0; i < size; i++) {
                auto it = qe.front();
                qe.pop();
                
                TreeNode* node = it.first;
                unsigned long long index = it.second - minIndex; 
                
                if (i == 0) first = index;
                if (i == size - 1) last = index;
                
                if (node->left) qe.push({node->left, 2 * index + 1});
                if (node->right) qe.push({node->right, 2 * index + 2});
            }
            
            maxWidth = max(maxWidth, (int)(last - first + 1));
        }
        
        return maxWidth;
    }
};
