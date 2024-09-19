class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& v, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: v)
        {
            int a = it[0];
            int b = it[1];
            int wt = it[2];

            adj[a].push_back({b,wt});
        }
        vector<int> ans(n,INT_MAX);
        queue<pair<int,pair<int,int>>> qe; //{val,{node,k}}
        ans[src] = 0;
        qe.push({0,{src,0}}); // {val,node,k}

        while(!qe.empty())
        {
            auto it = qe.front();
            qe.pop();

            int dist = it.first;
            int node = it.second.first;
            int k_val = it.second.second;

            // if(node==dst)   return dist;

            if(k_val>k) continue;


            for(auto child: adj[node])
            {
                int child_node = child.first;
                int child_wt = child.second;

                if(dist + child_wt < ans[child_node])
                {
                    ans[child_node] = dist + child_wt;
                    qe.push({ans[child_node],{child_node,k_val+1}});
                }
            }
        }

        if(ans[dst]==INT_MAX)   return -1;
        else                    return ans[dst];
    }
};