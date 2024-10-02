class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int maxv = -1;
        int ans = 0;
        for(int i=n-1;i>=0;i--)
        {
            maxv = max(maxv,v[i]);
            ans = max(ans,maxv-v[i]);
        }
        return ans;
    }
};