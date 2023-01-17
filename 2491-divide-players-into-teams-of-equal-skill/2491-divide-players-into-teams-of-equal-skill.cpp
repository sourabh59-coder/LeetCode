class Solution {
public:
    long long dividePlayers(vector<int>& v) {
        long long ans = 0;
        
        sort(v.begin(),v.end());
        
        int n = v.size();
        int m = (n/2);
        if(n%2!=0)
        {
            return -1;
        }
        int val = v[0]+v[n-1];
        for(int i=0;i<m;i++)
        {
            if(val==v[i]+v[n-1-i])
            {
                ans += (v[i]*v[n-1-i]);
            }
            else
            {
                return -1;
            }
        }
        
        return ans;
    }
};