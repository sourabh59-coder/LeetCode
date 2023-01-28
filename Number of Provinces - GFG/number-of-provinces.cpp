//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<int> v1[],vector<bool> &vis,int parent)
    {
        vis[parent] = true;
        
        for(int child: v1[parent])
        {
            if(vis[child]) continue;
            
            dfs(v1,vis,child);
        }
        
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> v1[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    v1[i].push_back(j);
                    v1[j].push_back(i);
                }
            }
        }
        vector<bool> vis(V,false);
        int cnt = 0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(v1,vis,i);
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends