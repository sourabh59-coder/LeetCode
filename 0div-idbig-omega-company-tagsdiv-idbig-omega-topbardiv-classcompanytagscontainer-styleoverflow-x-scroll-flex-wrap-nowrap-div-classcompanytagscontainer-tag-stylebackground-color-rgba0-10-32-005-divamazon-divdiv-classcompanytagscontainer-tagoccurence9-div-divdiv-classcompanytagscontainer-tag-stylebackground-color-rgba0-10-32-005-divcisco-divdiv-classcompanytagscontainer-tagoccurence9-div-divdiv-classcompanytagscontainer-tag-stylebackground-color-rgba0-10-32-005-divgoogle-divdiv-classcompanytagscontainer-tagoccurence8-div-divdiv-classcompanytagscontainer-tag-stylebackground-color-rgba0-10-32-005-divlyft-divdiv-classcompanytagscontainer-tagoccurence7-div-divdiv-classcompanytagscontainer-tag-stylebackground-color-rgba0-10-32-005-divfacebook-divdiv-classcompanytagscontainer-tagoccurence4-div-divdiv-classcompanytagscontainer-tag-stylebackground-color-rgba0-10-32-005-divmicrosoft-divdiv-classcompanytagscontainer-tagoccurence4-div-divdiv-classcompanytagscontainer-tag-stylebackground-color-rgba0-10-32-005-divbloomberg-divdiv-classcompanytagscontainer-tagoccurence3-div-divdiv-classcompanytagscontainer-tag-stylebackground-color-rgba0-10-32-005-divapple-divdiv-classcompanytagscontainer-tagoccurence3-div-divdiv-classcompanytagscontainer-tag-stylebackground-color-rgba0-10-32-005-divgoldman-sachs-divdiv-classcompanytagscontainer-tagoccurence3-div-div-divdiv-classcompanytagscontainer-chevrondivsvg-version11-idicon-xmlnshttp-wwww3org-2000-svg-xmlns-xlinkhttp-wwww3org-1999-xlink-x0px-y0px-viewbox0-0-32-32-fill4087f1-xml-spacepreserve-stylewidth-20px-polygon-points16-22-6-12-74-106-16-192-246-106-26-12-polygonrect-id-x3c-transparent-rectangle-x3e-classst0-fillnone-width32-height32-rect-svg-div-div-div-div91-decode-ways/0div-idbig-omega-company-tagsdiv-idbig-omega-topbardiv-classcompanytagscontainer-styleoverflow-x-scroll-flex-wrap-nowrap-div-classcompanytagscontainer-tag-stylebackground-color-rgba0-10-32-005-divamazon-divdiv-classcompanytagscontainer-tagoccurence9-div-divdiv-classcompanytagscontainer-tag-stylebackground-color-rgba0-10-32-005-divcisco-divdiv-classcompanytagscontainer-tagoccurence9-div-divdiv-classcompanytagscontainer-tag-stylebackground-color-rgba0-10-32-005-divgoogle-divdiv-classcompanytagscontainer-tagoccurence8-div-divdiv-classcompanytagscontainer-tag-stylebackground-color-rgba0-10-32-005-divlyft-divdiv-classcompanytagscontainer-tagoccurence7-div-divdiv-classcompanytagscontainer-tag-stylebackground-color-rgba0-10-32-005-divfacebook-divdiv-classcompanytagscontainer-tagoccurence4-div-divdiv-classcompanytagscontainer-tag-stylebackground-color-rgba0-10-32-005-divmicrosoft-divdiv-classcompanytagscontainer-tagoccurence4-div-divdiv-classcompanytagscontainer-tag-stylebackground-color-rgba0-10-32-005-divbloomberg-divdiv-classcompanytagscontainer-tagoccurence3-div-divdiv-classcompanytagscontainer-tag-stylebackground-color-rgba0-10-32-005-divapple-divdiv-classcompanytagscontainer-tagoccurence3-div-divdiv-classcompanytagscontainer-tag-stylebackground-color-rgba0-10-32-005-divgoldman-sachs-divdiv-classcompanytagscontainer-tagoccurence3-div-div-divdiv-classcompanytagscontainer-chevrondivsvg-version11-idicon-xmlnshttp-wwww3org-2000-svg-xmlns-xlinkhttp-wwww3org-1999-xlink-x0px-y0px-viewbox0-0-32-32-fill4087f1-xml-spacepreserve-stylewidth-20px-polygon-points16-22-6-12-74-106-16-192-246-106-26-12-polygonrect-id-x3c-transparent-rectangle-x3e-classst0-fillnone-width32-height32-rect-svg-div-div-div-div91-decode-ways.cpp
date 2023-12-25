class Solution {
public:
    int fun(string s,int i,vector<int> &dp)
    {
        if(i>=s.size())
        {
            return 1;
        }
        if(s[i]=='0')
        {
            return 0;
        }
        if(i==s.size()-1)
        {
            return 1;
        }
        
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        else if(s[i]=='1' || (s[i]=='2' && s[i+1]>=48 && s[i+1]<=54))
        {
            return dp[i] = fun(s,i+1,dp)+fun(s,i+2,dp);
        }
        else
        {
            return dp[i] = fun(s,i+1,dp);
        }
    }
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,-1);
        return fun(s,0,dp);
    }
};