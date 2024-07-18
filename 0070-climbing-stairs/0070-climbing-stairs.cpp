class Solution {
public:
    int fun(int n,vector<int> &dp)
    {
        if(n==0)    return 1;

        if(dp[n]!=-1)   return dp[n];

        int one  = 0, two = 0;
        if(n>=1) one = fun(n-1,dp);
        if(n>=2) two = fun(n-2,dp);

        return dp[n] = (one+two);
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1,0);
        // dp[0] = 1;
        int curr=1,prev=1,prevprev=1;
        for(int i=1;i<=n;i++)
        {
            int one  = 0, two = 0;
            if(i>=1) one = prev;
            if(i>=2) two = prevprev;

            curr = (one+two);
            prevprev = prev;
            prev = curr;
        }
        return curr;
        // return fun(n,dp);
    }
};