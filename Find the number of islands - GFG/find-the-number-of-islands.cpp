//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void fun(vector<vector<char>> &v,int i,int j)
    {
        int m = v.size();
        int n = v[0].size();
        
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return;
        }
        if(v[i][j]!='1')
        {
            return;
        }
        v[i][j] = '2';
        
        fun(v,i+1,j);
        fun(v,i-1,j);
        fun(v,i,j+1);
        fun(v,i,j-1);
        fun(v,i+1,j+1);
        fun(v,i-1,j-1);
        fun(v,i+1,j-1);
        fun(v,i-1,j+1);
    }
    int numIslands(vector<vector<char>>& v) {
        // Code here
        int m = v.size();
        int n = v[0].size();
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]=='1')
                {
                    cnt++;
                    fun(v,i,j);
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends