class Solution {
public:
    int fun(string &s1,string &s2,int n,int m,vector<vector<int>> &dp)
    {
        if(n==0 || m==0)    return 0;

        if(dp[n][m]!=-1)    return dp[n][m];

        if(s1[n-1]==s2[m-1])    return dp[n][m] =  (1 + fun(s1,s2,n-1,m-1,dp));

        else    return dp[n][m] = max(fun(s1,s2,n-1,m,dp) , fun(s1,s2,n,m-1,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));

        return fun(s1,s2,n,m,dp);
    }
};