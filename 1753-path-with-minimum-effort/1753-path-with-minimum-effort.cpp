class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    int minimumEffortPath(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> ans(n, vector<int> (m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> qe;
        ans[0][0] = 0;
        qe.push({0,{0,0}});
        while(!qe.empty())
        {
            auto it = qe.top();
            qe.pop();

            int val = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x==n-1 && y==m-1)    return ans[x][y];

            for(auto moment: moments)
            {
                int i = x + moment.first;
                int j = y + moment.second;

                if(check(i,j,n,m))
                {
                    int value = max(val,abs(v[x][y]-v[i][j]));
                    if(ans[i][j] > value)
                    {
                        ans[i][j] = value;
                        qe.push({value,{i,j}});
                    }
                }
            }
        }
        return -1;
    }
};