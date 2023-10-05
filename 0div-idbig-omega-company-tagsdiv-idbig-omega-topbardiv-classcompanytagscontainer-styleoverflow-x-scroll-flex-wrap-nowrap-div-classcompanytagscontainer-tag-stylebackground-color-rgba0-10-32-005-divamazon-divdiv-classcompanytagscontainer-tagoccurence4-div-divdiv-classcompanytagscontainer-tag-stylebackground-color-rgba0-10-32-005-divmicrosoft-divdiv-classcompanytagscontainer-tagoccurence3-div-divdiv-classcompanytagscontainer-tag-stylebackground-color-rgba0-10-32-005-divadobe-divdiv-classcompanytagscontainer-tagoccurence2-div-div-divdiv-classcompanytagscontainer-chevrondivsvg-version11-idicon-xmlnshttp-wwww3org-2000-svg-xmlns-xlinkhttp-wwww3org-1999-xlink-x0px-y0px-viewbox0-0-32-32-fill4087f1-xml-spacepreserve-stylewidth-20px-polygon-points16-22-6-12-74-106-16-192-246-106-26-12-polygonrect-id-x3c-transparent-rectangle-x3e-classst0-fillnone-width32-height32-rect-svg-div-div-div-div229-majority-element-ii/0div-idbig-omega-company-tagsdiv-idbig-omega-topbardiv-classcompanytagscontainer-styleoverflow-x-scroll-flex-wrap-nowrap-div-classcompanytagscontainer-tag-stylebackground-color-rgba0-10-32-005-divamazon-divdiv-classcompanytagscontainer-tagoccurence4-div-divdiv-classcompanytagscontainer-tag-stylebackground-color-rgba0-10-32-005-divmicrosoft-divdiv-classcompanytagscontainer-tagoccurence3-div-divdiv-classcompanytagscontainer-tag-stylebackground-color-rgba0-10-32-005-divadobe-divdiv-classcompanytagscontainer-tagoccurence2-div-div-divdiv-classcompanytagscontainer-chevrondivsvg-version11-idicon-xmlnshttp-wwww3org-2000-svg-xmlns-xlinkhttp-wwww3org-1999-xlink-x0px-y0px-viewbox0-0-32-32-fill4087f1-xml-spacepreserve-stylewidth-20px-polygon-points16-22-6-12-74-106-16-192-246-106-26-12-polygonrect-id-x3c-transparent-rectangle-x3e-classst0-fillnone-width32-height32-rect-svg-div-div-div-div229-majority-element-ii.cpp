class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        map<int,int> mp;
        int n = v.size()/3;
        for(int i=0;i<v.size();i++)
        {
            mp[v[i]]++;
        }
        vector<int> v1;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>n)
            {
                v1.push_back(it->first);
            }
        }
        return v1;
    }
};