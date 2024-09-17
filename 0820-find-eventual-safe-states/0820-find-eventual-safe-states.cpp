class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                indegree[i]++;
                adj[v[i][j]].push_back(i);

            }
        }
        vector<int> ans;
        queue<int> qe;
        for(int i=0;i<indegree.size();i++)  if(indegree[i]==0)  qe.push(i);
        while(!qe.empty())
        {
            auto it = qe.front();
            qe.pop();

            ans.push_back(it);

            for(auto child : adj[it])
            {
                indegree[child]--;
                if(indegree[child]==0)
                {
                    qe.push(child);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};