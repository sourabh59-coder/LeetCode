class Solution {
public:
int solve(int i,int j,vector<vector<int>>obstacleGrid,vector<vector<int>>&dp,int n,int m){
    if(i>=n||j>=m||obstacleGrid[i][j]==1)return dp[i][j]=0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==n-1&&j==m-1)return dp[i][j]= 1;
    return dp[i][j]=solve(i+1,j,obstacleGrid,dp,n,m)+solve(i,j+1,obstacleGrid,dp,n,m);
    

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1)return 0;
        // cout<<m<<n;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        solve(0,0,obstacleGrid,dp,n,m);
        return dp[0][0];
        
        
    }
};