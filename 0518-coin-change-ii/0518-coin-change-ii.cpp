class Solution {
public:

    int dp[5001][301];

    int find(int amount,int i, vector<int> coins)
    {
        if(amount<0)
        return 0;
        
        if(amount==0)
            return 1;
        if(dp[amount][i]!=-1)
            return dp[amount][i];
            if(i==coins.size())
                return 0;

        return dp[amount][i]=find(amount-coins[i],i,coins)+find(amount,i+1,coins);

    }
    int change(int amount, vector<int>& coins) {
        
        for(int i=0;i<5001;i++)
        {
            for(int j=0;j<301;j++)
            {
                dp[i][j]=-1;
            }
        }
        return find(amount,0,coins);
    }
};