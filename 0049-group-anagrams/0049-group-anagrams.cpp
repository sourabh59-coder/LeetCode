class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<vector<string>> ans;
        map<string,vector<string>> mp;
        for(int i=0;i<s.size();i++)
        {
            string s1 = s[i];
            sort(s1.begin(),s1.end());
            mp[s1].push_back(s[i]);
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};