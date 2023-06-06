class Solution {
private:
    void bfs(int v,vector<vector<int>> &adj,vector<int> &col,bool &ans)
    {
        queue<int> qe;
        qe.push(v);
        col[v] = 0;
        
        while(!qe.empty())
        {
            int node = qe.front();
            qe.pop();
            
            for(auto child: adj[node])
            {
                if(col[child]==-1)
                {
                    col[child] = 1-col[node];
                    qe.push(child);
                }
                else
                {
                    if(col[child]==col[node])   ans = false;
                }
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
                bfs(i,adj,col,ans);
            }
        }
        
        return ans;
    }
};