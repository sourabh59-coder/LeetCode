class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1},{-1,1},{1,-1},{-1,-1},{1,1}};
    bool check(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
        // int ans = INT_MAX;
        int n = v.size();
        int m = v[0].size();
        if(v[0][0]==1 || v[n-1][m-1])   return -1;
        // int  cnt = 0;
        vector<vector<int>> ans(n, vector<int> (m,INT_MAX));
        queue<pair<int,int>> qe;
        qe.push({0,0});
        ans[0][0] = 1;

        int cnt = 0;

        while(!qe.empty())
        {
            int si = qe.size();
            cnt++;
            while(si--)
            {
                auto it = qe.front();
                qe.pop();

                int x = it.first;
                int y = it.second;

                if(x==n-1 && y==m-1)    return cnt;

                for(auto moment: moments)
                {
                    int  i = x + moment.first;
                    int  j = y + moment.second;

                    if(check(i,j,n,m) && v[i][j]==0 && ans[i][j] > 1 + cnt)
                    {
                        ans[i][j] = 1 + cnt;
                        qe.push({i,j});
                    }
                }
            }
        }

        return -1;
    }
};