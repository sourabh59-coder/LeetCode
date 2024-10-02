class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        int maxv = v[0];
        vector<int> lm(n,0),rm(n,0);
        for(int i=0;i<n;i++)
        {
            maxv = max(maxv,v[i]);
            lm[i] = maxv;
        }
        maxv = v[n-1];
        for(int i=n-1;i>=0;i--)
        {
            maxv = max(maxv,v[i]);
            rm[i] = maxv;
        }

        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            int val = min(lm[i],rm[i]);
            ans += (val-v[i]);
        }
        return ans;
    }
};