class Solution {
public:
    int Fun(vector<vector<int>> &v,int n,int pos,vector<vector<int>> &dp,int k)
    {
        int i;
        if(pos>=n || k==0)  return 0;
        
        if(dp[pos][k]!=-1)  return dp[pos][k];
        
        for(i=pos+1;i<n;i++)    if(v[i][0] > v[pos][1]) break;
        
        return  dp[pos][k] = max(Fun(v,n,pos+1,dp,k),v[pos][2]+Fun(v,n,i,dp,k-1));
    }
    int maxValue(vector<vector<int>>& v, int k) {
        sort(v.begin(),v.end());
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (k+1,-1));
        return Fun(v,n,0,dp,k);
    }
};