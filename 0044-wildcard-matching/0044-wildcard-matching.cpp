class Solution {
public:
    int fun(string &s,string &p,int n,int m,vector<vector<int>> &dp)
    {
        if(n==0 && m==0)    return 1;
        if (m == 0) return 0; 
        if (n == 0) {
            for (int i = 0; i < m; i++) {
                if (p[i] != '*') return 0;
            }
            return 1;
        }

        if(dp[n][m]!=-1)    return dp[n][m];

        if(s[n-1]==p[m-1])  return dp[n][m]=  (fun(s,p,n-1,m-1,dp));

        if(p[m-1]=='*')     return dp[n][m] = (fun(s,p,n-1,m,dp) || fun(s,p,n-1,m-1,dp) || fun(s,p,n,m-1,dp));

        if(p[m-1]=='?')     return dp[n][m] = (fun(s,p,n-1,m-1,dp));

        return dp[n][m] = 0;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        return fun(s,p,n,m,dp);
    }
};