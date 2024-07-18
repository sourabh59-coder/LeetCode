class Solution {
public:
    int LongestCommomSubstring(vector<int> v1,vector<int> v2)
    {
        int n = v1.size();
        
        int m = v2.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        
        int ans = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(v1[i-1]==v2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        return ans;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return LongestCommomSubstring(nums1,nums2);
    }
};