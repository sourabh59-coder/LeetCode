//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void DFS(int v,bool &ans,vector<int> &col,vector<int> adj[])
    {
        
        for(auto child: adj[v])
        {
            if(col[child]==-1)
            {
                col[child] = 1-col[v];
                DFS(child,ans,col,adj);
            }
            else
            {
                if(col[child]==col[v])  ans = false;
            }
        }
    }
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    bool ans = true;
	    vector<int> col(n+1,-1);
    
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                col[i] = 0;
                DFS(i,ans,col,adj);
            }
        }
        
        return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends