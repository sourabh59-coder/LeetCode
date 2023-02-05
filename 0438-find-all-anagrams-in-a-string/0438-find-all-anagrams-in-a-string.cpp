class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v1(27,0);
        vector<int> v2(27,0);
        if(p.length()>s.length())
        {
            return {};
        }
        for(int i=0;i<p.size();i++)
        {
            int val = p[i]-'a';
            v1[val]++;
            
            int val1 = s[i]-'a';
            v2[val1]++;
        }
        
        vector<int> ans;
        if(v1==v2)
        {
            ans.push_back(0);
        }
        
        for(int i=0;i<s.length()-p.length();i++)
        {
            int val1 = s[i]-'a';
            int val2 = s[(i+p.size())]-'a';
            
            v2[val2]++;
            v2[val1]--;
            
            if(v1==v2)
            {
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};