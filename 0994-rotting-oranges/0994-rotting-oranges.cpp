class Solution {
public:
    vector<pair<int,int>> movements{{1,0},{-1,0},{0,1},{0,-1}};
    int fun(vector<vector<int>> &v)
    {
        int ans = 0;
        queue<pair<int,pair<int,int>>> qe;
        int n = v.size();
        int m = v[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==2)
                {
                    qe.push({0,{i,j}});
                }
            }
        }
        
        while(!qe.empty())
        {
            auto node = qe.front();
            qe.pop();
            
            int an = node.first;
            int i = node.second.first;
            int j = node.second.second;
            
            for(auto movement: movements)
            {
                int child_i = i+movement.first;
                int child_j = j+movement.second;
                
                if(child_i>=0 && child_i<n && child_j>=0 && child_j<m)
                {
                    if(v[child_i][child_j]==1)
                    {
                        v[child_i][child_j] = 2;
                        qe.push({an+1,{child_i,child_j}});
                        ans = max(ans,an+1);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1)
                {
                    return -1;
                }
            }
        }
        
        return ans;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // int ans = 0;
        return fun(grid);
    }
};