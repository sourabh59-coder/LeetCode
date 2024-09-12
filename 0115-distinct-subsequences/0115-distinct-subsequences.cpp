class Solution {
public:
    int fun(string &s,string &t,int n,int m,vector<vector<int>> &dp)
    {
        if(m==0)    return 1;
        if(n==0)    return 0;

        if(dp[n][m]!=-1)    return dp[n][m];

        // notTake
        int notTake = fun(s,t,n-1,m,dp);

        //Take
        int Take = 0;
        if(s[n-1]==t[m-1])  Take = fun(s,t,n-1,m-1,dp);

        return dp[n][m] = (Take + notTake);
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        return fun(s,t,n,m,dp);
    }
};