class Solution {
public:
    int singleNumber(vector<int>& v) {
        int ans = 0;
        
        for(int i=0;i<32;i++)
        {
            int cnt = 0;
            int mask = 1<<i;
            for(int j=0;j<v.size();j++)
            {
                if(v[j]&mask)
                {
                    cnt++;
                }
            }
            if(cnt%3!=0)
            {
                ans += (mask);
            }
        }
        
        return ans;
    }
};