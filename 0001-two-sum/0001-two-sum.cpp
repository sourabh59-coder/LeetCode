class Solution {
public:
    vector<int> twoSum(vector<int>& v, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<v.size();i++)
        {
            mp[v[i]] = i;
        }
        
        for(int i=0;i<v.size();i++)
        {
            int kp = k-v[i];
            if(mp.find(kp)!=mp.end())
            {
                if(mp[kp]!=i)
                {
                    ans.push_back(i);
                    ans.push_back(mp[kp]);
                    break;
                }
            }
        }
        return ans;
    }
};