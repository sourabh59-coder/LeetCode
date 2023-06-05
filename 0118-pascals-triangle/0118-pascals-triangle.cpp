class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows>=2)
        {
            ans.push_back({1,1});
        }
        for(int i=3;i<=numRows;i++)
        {
            vector<int> v;
            v.push_back(1);
            
            vector<int> vl = ans[i-2];
            for(int j=0;j<vl.size()-1;j++)
            {
                v.push_back(vl[j]+vl[j+1]);
            }
            
            v.push_back(1);
            
            ans.push_back(v);
        }
        return ans;
    }
};