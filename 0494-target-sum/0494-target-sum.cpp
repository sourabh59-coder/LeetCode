class Solution {
public:
    int findTargetSumWays(vector<int>& v, int d) {
        int n = v.size();
        int sum = 0;
        for(auto it: v) sum += it;
        
        vector<vector<int>> dp(n+1, vector<int> (sum+1,0));
        // fun(v,n,sum,dp);
        for(int i=0;i<=n;i++)   dp[i][0] = 1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                //notTake
                int notTake = dp[i-1][j];
                
                // Take
                int Take = 0;
                
                if(v[i-1]<=j) Take = dp[i-1][j-v[i-1]];
                
                dp[i][j] = (Take+notTake);
            }
        }
        int ans = 0;
        // return dp[n][sum];
        for(int j=0;j<=sum;j++)
        {
            if(dp[n][j]!=0)
            {
                if(abs(sum-(2*j))==abs(d) && (sum/2) >= j)  ans += dp[n][j];
            }
        }
        
        return ans;
    }
};