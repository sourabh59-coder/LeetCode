class Solution {
public:
    int fun(int n,int k,int target,vector<vector<int>> &dp)
    {
        if(n==0 && target==0)
        {
            return 1;
        }
        if(n==0)
        {
            return 0;
        }
        
        if(dp[n][target]!=-1)
        {
            return dp[n][target];
        }
        
        int take = 0;
        
        for(int i=1;i<=k;i++)
        {
            if(target>=i)
            {
                take += fun(n-1,k,target-i,dp)%(1000000007);
                take %= 1000000007;
            }
        }
        
        return dp[n][target] = take;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return fun(n,k,target,dp);
    }
};