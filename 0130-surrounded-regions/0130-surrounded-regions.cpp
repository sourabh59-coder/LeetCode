class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    void dfs(vector<vector<char>> &v,int i,int j,int n,int m,vector<vector<int>> &vis)
    {
        vis[i][j] = 1;

        for(auto moment: moments)
        {
            int x = i + moment.first;
            int y = j + moment.second;

            if(check(x,y,n,m) && !vis[x][y] && v[x][y]=='O')
            {
                dfs(v,x,y,n,m,vis);
            }
        }
    }
    void dfs_change(vector<vector<char>> &v,int i,int j,int n,int m,vector<vector<int>> &vis)
    {
        v[i][j] = 'X';
        vis[i][j] = 1;

        for(auto moment: moments)
        {
            int x = i + moment.first;
            int y = j + moment.second;

            if(check(x,y,n,m) && !vis[i][j] && v[i][j]=='O')
            {
                dfs_change(v,x,y,n,m,vis);
            }
        }
    }
    void solve(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();

        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(v[i][j]=='O' && !vis[i][j])
                    {
                        dfs(v,i,j,n,m,vis);
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && v[i][j]=='O')
                {
                    dfs_change(v,i,j,n,m,vis);
                }
            }
        }
    }
};