class Solution {
public:
    int fun(vector<int> &v,int ind,int prev,int n,vector<vector<int>> &dp)
    {
        if(ind==n)  return 0;

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        // notTake 
        int notTake = 0 + fun(v,ind+1,prev,n,dp);

        //Take
        int Take = 0;

        if(prev==-1 || v[ind]>v[prev])  Take = fun(v,ind+1,ind,n,dp) + 1;

        return dp[ind][prev+1] = max(notTake,Take);
    }
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return fun(v,0,-1,n,dp);
    }
};