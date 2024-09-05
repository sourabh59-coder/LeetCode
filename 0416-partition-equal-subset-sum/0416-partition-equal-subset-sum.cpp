class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int sum,vector<vector<int>> &dp)
    {
        if(sum==0)  return 1;
        if(ind==n)  return 0;


        if(dp[ind][sum]!=-1)    return dp[ind][sum];
        //notTake
        int notTake = fun(v,ind+1,n,sum,dp);

        //Take 
        int Take = 0;
        if(v[ind]<=sum) Take = fun(v,ind+1,n,sum-v[ind],dp);

        return dp[ind][sum] = (Take||notTake);
    }
    bool canPartition(vector<int>& v) {
        int n = v.size();
        int sum = 0;
        for(int i=0;i<n;i++)    sum += v[i];

        if(sum%2!=0)    return false;
        sum /= 2;

        vector<vector<int>> dp(n+1, vector<int> (sum+1,-1));
        return fun(v,0,n,sum,dp);
    }
};