class Solution {
public:
    vector<pair<int,int>> movements{{1,0},{-1,0},{0,1},{0,-1}};
    void DFS(vector<vector<char>> &v,vector<vector<int>> &vis,int i,int j,int m,int n)
    {
        vis[i][j] = 1;
        
        for(auto movement: movements)
        {
            int child_i = movement.first+i;
            int child_j = movement.second+j;
            
            if(child_i>=0 && child_i<m && child_j>=0 && child_j<n)
            {
                if(v[child_i][child_j]=='O' && !vis[child_i][child_j])
                {
                    DFS(v,vis,child_i,child_j,m,n);
                }
            }
        }
    }
    void Reg(vector<vector<char>> &v,int i,int j,int m,int n)
    {
        v[i][j] = 'X';
        
        for(auto movement: movements)
        {
            int child_i = movement.first+i;
            int child_j = movement.second+j;
            
            if(child_i>=0 && child_i<m && child_j>=0 && child_j<n)
            {
                if(v[child_i][child_j]=='O')
                {
                    Reg(v,child_i,child_j,m,n);
                }
            }
        }
    }
    void solve(vector<vector<char>>& v) {
        int m = v.size(), n = v[0].size();
        vector<vector<int>> vis(m, vector<int> (n,0));
        
        for(int j=0;j<n;j++)
        {
            if(v[0][j]=='O')
            {
                DFS(v,vis,0,j,m,n);
            }
            if(v[m-1][j]=='O')
            {
                DFS(v,vis,m-1,j,m,n);
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(v[i][0]=='O')
            {
                DFS(v,vis,i,0,m,n);
            }
            if(v[i][n-1]=='O')
            {
                DFS(v,vis,i,n-1,m,n);
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]=='O' && !vis[i][j])
                {
                    Reg(v,i,j,m,n);
                }
            }
        }
    }
};