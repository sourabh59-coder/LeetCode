class Solution {
public:
    int fun(vector<int> &v,int ind,int prev,int n,vector<vector<int>> &dp)
    {
        if(ind==n+1)  return 0;

        if(dp[ind][prev]!=-1) return dp[ind][prev];

        // notTake 
        int notTake = 0 + fun(v,ind+1,prev,n,dp);

        //Take
        int Take = 0;

        if(prev==0 || v[ind-1]>v[prev-1])  Take = fun(v,ind+1,ind,n,dp) + 1;

        return dp[ind][prev] = max(notTake,Take);
    }
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+2, vector<int> (n+1,0));

        for(int i=n;i>=1;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                // notTake 
                int notTake = 0 + dp[i+1][j];

                //Take
                int Take = 0;

                if(j==0 || v[i-1]>v[j-1])  Take = dp[i+1][i] + 1;

                dp[i][j] = max(notTake,Take);
            }
        }
        return dp[1][0];        
        // return fun(v,1,0,n,dp);
    }
};