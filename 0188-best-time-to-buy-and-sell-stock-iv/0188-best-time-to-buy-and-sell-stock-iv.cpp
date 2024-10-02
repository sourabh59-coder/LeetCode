class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int k,int buy,vector<vector<vector<int>>> &dp)
    {
        if(ind==n || k==0)  return 0;

        if(dp[ind][k][buy]!=-1) return dp[ind][k][buy];

        if(buy==0)
        {
            int Take = -v[ind] + fun(v,ind+1,n,k,1,dp);

            int notTake = 0 + fun(v,ind+1,n,k,buy,dp);

            return dp[ind][k][buy] = max(Take,notTake);
        }
        else
        {
            int Take = v[ind] + fun(v,ind+1,n,k-1,0,dp);

            int notTake = 0 + fun(v,ind+1,n,k,buy,dp);

            return dp[ind][k][buy] = max(Take,notTake);
        }
    }
    int maxProfit(int k, vector<int>& v) {
        int n = v.size();
        // int k = 2;
        int buy = 0;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (k+1, vector<int> (2,-1)));
        return fun(v,0,n,k,buy,dp);
    }
};