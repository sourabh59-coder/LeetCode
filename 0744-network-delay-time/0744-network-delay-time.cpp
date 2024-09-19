class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges)
        {
            int a = it[0]-1;
            int b = it[1]-1;
            int wt = it[2];

            adj[a].push_back({b,wt});
        }

        vector<int> ans(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qe;
        ans[k-1] = 0;
        qe.push({0,k-1});

        while(!qe.empty())
        {
            auto it = qe.top();
            qe.pop();

            int node = it.second;
            int wt = it.first;

            for(auto child: adj[node])
            {
                int child_node = child.first;
                int child_wt = child.second;

                if(child_wt + wt < ans[child_node])
                {
                    ans[child_node] = child_wt + wt;
                    qe.push({ans[child_node],child_node});
                }
            }
        }

        int ans_val = -1;
        for(auto it : ans)
        {
            if(it==INT_MAX) return -1;
            ans_val = max(ans_val,it);
        }
        return ans_val;
    }
};