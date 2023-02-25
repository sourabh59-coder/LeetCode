class Solution {
public:
    int maxProfit(vector<int>& v) {
        vector<int> minv(v.size());
        minv[0] = v[0];
        for(int i=1;i<v.size();i++)
        {
            minv[i] = min(v[i],minv[i-1]);
        }
        int ans = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]-minv[i]>ans)
            {
                ans = v[i]-minv[i];
            }
        }
        return ans;
    }
};