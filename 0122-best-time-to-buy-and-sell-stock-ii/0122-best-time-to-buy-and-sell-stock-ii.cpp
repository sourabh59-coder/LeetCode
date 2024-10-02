class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int buy,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            return 0;
        }

        if(dp[ind][buy]!=-1)    return dp[ind][buy];

        if(buy==1)
        {
            int take = v[ind] + fun(v,ind+1,n,0,dp);

            int notTake = 0 + fun(v,ind+1,n,buy,dp);

            return dp[ind][buy] = max(take,notTake);
        }
        else
        {
            int take = -v[ind] + fun(v,ind+1,n,1,dp);

            int notTake = 0 + fun(v,ind+1,n,buy,dp);

            return dp[ind][buy] = max(take,notTake);
        }
    }
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int buy = 0;
        vector<vector<int>> dp(n+1, vector<int> (2,-1));
        return fun(v,0,n,buy,dp);
    }
};