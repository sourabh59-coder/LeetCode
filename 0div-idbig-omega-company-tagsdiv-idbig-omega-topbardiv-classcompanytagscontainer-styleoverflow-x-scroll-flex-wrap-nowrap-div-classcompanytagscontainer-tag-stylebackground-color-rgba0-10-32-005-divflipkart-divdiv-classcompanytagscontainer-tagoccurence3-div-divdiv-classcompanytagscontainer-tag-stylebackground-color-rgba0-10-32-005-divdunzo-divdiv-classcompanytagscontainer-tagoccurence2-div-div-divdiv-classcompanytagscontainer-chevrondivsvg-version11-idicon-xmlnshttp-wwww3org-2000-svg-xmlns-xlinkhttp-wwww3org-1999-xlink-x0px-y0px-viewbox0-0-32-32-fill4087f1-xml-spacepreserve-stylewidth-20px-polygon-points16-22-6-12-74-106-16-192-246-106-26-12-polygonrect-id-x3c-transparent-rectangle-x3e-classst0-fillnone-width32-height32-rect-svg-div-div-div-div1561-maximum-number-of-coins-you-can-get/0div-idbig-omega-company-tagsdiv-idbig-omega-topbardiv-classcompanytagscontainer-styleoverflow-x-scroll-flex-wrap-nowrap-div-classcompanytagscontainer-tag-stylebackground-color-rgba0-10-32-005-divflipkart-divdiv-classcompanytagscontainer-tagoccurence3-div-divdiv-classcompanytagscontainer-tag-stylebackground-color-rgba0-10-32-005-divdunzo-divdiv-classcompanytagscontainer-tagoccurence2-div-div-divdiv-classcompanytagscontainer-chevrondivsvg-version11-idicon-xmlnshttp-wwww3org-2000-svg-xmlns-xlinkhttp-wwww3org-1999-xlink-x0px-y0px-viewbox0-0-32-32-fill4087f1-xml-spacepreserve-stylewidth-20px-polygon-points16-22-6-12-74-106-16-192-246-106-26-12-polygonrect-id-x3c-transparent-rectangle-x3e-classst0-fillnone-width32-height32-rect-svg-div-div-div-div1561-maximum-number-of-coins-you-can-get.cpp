class Solution {
public:
    int maxCoins(vector<int>& v) {
        sort(v.begin(),v.end(),greater<int>());
        int ans = 0;
        int n = v.size()/3;
        for(int i=1;i<v.size()-n;i=i+2)
        {
            ans += v[i];
        }
        return ans;
    }
};