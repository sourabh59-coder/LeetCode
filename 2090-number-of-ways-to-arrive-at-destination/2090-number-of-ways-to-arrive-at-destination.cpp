class Solution {
public:
    const long long INF = LLONG_MAX;
    const long long mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& v) {
        vector<vector<pair<long long,long long>>> adj(n);
        for(auto it: v)
        {
            int a = it[0];
            int b = it[1];
            int wt = it[2];
            adj[a].push_back({b,wt});
            adj[b].push_back({a,wt});
        }
        long long src = 0, dest = n-1;
        vector<long long> cnt(n,0);
        vector<long long> ans(n,INF);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> qe;
        qe.push({0,src});
        ans[src] = 0;
        cnt[src] = 1;
        
        while(!qe.empty())
        {
            auto it = qe.top();
            qe.pop();

            long long node = it.second;
            long long dist = it.first;
            long long count = cnt[node] % mod;

            if(node==dest)  return (int)count;

            for(auto child: adj[node])
            {
                long long child_node = child.first;
                long long child_wt = child.second;

                if(child_wt==INF || dist==INF)  continue;

                long long cal = child_wt + dist;

                if(cal==ans[child_node])
                {
                    long long val = (cnt[child_node] + cnt[node]) % mod;
                    cnt[child_node] = val;
                }

                if(cal < ans[child_node])
                {
                    ans[child_node] = child_wt + dist;
                    cnt[child_node] = cnt[node] % mod;
                    qe.push({ans[child_node],child_node});
                }
            }
        }

        return -1;
    }
};
