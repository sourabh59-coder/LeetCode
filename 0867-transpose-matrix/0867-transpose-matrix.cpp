class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& v) {
        vector<vector<int>> ans(v[0].size(),vector<int> (v.size(),0));
        
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[0].size();j++)
            {
                ans[j][i] = v[i][j];
            }
        }
        
        return ans;
    }
};