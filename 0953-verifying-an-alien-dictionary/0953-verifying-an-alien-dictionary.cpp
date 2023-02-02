class Solution {
public:
    map<char,int> mp;
    bool comp(string s1,string s2)
    {
        for(int i=0;i<min(s1.length(),s2.length());i++)
        {
            if(mp[s1[i]]==mp[s2[i]])
            {
                continue;
            }
            return (mp[s1[i]]<mp[s2[i]]);
        }
        return (s1.length()<=s2.length());
    }
    bool isAlienSorted(vector<string>& v, string s) {
        mp.clear();
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]] = (i+1);
        }
        
        for(int i=0;i<v.size()-1;i++)
        {
            if(!comp(v[i],v[i+1]))
            {
                return false;
            }
        }
        return true;
    }
};