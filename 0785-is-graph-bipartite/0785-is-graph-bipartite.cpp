class Solution {
private:
    void dfs(int v,int par,vector<vector<int>> &adj,vector<int> &col,bool &ans)
    {
        if(par==-1)
        {
            col[v] = 0;
        }
        else
        {
            col[v] = 1-col[par];
        }
        
        for(auto child: adj[v])
        {
            if(col[child]==-1)
            {
                dfs(child,v,adj,col,ans);
            }
            else
            {
                if(col[child]==col[v])    ans = false;
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> col(n+1,-1);
        
        bool ans = true;
        
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                dfs(i,-1,adj,col,ans);
            }
        }
        
        return ans;
    }
};