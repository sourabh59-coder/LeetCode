class Solution {
public:
    int minimumRounds(vector<int>& v) {
        map<int,int> mp;
        for(int i=0;i<v.size();i++)
        {
            mp[v[i]]++;
        }
        
        int ans = 0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==1)
            {
                return -1;
            }
            else
            {
                ans += ceil((double)it->second/3);
            }
        }
        
        return ans;
    }
};