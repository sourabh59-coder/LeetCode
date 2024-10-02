class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int buy,int fee,vector<vector<int>> &dp)
    {
        if(ind==n)  return 0;

        if(dp[ind][buy]!=-1)    return dp[ind][buy];

        if(buy==0)
        {
            int Take = -v[ind] + fun(v,ind+1,n,1,fee,dp);
            int notTake = 0 + fun(v,ind+1,n,buy,fee,dp);

            return dp[ind][buy] = max(Take,notTake);
        }
        else
        {
            int Take = v[ind] + fun(v,ind+1,n,0,fee,dp) - fee;
            int notTake = 0 + fun(v,ind+1,n,buy,fee,dp);

            return dp[ind][buy] = max(Take ,notTake);
        }
    }
    int maxProfit(vector<int>& v, int f) {
        int n = v.size();
        int buy = 0;
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return fun(v,0,n,buy,f,dp);
    }
};