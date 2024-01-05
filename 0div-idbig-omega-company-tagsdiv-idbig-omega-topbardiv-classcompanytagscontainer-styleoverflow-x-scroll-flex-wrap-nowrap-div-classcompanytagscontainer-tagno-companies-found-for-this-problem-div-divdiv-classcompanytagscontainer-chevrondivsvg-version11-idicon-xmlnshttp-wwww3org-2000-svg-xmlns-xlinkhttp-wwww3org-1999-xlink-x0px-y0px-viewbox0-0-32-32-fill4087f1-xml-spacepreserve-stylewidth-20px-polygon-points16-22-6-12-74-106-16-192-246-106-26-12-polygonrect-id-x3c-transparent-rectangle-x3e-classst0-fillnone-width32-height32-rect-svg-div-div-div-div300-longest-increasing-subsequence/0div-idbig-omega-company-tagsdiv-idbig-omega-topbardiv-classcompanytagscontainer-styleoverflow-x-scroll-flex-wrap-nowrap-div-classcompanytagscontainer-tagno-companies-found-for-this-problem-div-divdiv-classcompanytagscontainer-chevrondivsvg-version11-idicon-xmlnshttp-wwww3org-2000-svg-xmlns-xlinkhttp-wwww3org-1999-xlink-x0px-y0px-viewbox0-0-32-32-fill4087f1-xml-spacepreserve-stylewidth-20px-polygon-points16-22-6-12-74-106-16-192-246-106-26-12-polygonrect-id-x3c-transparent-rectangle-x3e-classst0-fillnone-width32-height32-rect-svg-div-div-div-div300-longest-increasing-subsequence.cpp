class Solution {
public:
    int fun(vector<int> &v,int n,int i,int prev_ind,vector<vector<int>> &dp)
    {
        if(i==n)    return 0;
        
        if(dp[i][prev_ind+1]!=-1)   return dp[i][prev_ind+1];

        int NotTake = 0+fun(v,n,i+1,prev_ind,dp);

        int Take = 0;

        if(prev_ind==-1 || v[prev_ind]<v[i])
        {
            Take = 1+fun(v,n,i+1,i,dp);
        }

        return dp[i][prev_ind+1] = max(Take,NotTake);
    }

    int lengthOfLIS(vector<int>& v)
    {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return fun(v,v.size(),0,-1,dp);
    }
};