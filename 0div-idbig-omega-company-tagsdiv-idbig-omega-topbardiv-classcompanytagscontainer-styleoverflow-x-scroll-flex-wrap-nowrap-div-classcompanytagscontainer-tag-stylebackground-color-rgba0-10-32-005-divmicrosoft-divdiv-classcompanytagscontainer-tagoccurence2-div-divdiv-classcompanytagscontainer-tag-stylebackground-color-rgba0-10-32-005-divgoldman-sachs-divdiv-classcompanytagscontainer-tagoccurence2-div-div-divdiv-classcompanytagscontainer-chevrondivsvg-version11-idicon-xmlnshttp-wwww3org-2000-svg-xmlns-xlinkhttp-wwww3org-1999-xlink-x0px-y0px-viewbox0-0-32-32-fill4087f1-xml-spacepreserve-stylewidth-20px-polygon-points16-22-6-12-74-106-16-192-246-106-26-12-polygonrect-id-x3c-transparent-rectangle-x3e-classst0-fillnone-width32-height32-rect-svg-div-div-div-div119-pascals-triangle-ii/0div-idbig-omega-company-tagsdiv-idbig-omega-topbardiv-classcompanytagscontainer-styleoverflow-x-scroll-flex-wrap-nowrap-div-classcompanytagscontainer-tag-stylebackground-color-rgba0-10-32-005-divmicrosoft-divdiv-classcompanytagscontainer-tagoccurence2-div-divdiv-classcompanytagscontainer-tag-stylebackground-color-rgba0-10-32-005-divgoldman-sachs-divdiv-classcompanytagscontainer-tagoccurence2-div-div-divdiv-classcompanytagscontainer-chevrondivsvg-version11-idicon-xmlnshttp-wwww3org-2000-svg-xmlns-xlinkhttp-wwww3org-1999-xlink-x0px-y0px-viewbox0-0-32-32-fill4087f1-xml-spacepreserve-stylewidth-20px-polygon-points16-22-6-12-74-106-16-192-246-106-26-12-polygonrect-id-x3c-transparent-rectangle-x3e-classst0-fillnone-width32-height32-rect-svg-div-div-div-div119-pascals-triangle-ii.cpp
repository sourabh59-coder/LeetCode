class Solution {
public:
    vector<int> getRow(int m) {
        vector<vector<int>> ans;
        int n = m+1;
        for(int i=1;i<=n;i++)
        {
            vector<int> v(i,1);
            ans.push_back(v);
        }
        for(int i=2;i<n;i++)
        {
            for(int j=1;j<ans[i].size()-1;j++)
            {
                ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
            }
        }
        
        return ans[m];
    }
};