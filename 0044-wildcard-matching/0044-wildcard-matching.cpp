class Solution {
public:
    int fun(string &s1,string &s2,int i,int j, vector<vector<int>> &dp)
    {
        if(i<0 && j<0)  return true;

        if(i<0 && j>=0)
        {
            for(int k =0;k<=j;k++)
            {
                if(s2[k]!='*')  return false;
            }

            return true;
        }

        if(j<0 && i>=0) return false;

        if(dp[i][j]!=-1)    return dp[i][j];

        if(s1[i]==s2[j])    return dp[i][j] = fun(s1,s2,i-1,j-1,dp);

        if(s2[j]=='?')  return dp[i][j] = fun(s1,s2,i-1,j-1,dp);

        if(s2[j]=='*')  return dp[i][j] = fun(s1,s2,i-1,j,dp) | fun(s1,s2,i-1,j-1,dp) | fun(s1,s2,i,j-1,dp);

        return dp[i][j] = false;
    }
    bool isMatch(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        // return fun(s1,s2,n-1,m-1,dp);
        dp[0][0] = 1;

        for(int j=1;j<=m;j++)
        {
            bool ans = 1;

            for(int k=1;k<=j;k++)
            {
                if(s2[k-1]!='*')    ans = 0;
            }

            dp[0][j] = ans;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])    dp[i][j] = dp[i-1][j-1];

                if(s2[j-1]=='?')  dp[i][j] = dp[i-1][j-1];

                if(s2[j-1]=='*')  dp[i][j] = dp[i-1][j] | dp[i-1][j-1] | dp[i][j-1];
            }
        }

        return dp[n][m];
    }
};