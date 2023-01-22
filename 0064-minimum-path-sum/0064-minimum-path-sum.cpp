class Solution {

// private:
// int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>>& grid)
// {
//   if(i == 0 && j == 0)
//   {
//     return grid[0][0];
//   }

//   if(i < 0 || j < 0)
//   {
//     return 1e9;
//   }

//   if(dp[i][j] != -1)
//   {
//     return dp[i][j];
//   }

//   int up = grid[i][j] + solve(i-1,j,dp,grid);
//   int left = grid[i][j] + solve(i,j-1,dp,grid);

//   return dp[i][j] = min(up,left);
// }
public:
    int minPathSum(vector<vector<int>>& grid) {

      int n = grid.size();
      int m = grid[0].size();

      vector<vector<int>> dp(n,vector<int>(m,0));
        
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(i==0 && j==0)
              {
                  dp[i][j] = grid[i][j];
              }
              else
              {
                  int u = 1e9;
                  int l = 1e9;
                  
                  if(i>0)   u = dp[i-1][j];
                  if(j>0)   l = dp[i][j-1];
                  
                  dp[i][j] += grid[i][j];
                  dp[i][j] += min(l,u);
              }
          }
      }
        
      return dp[n-1][m-1];
    }
};