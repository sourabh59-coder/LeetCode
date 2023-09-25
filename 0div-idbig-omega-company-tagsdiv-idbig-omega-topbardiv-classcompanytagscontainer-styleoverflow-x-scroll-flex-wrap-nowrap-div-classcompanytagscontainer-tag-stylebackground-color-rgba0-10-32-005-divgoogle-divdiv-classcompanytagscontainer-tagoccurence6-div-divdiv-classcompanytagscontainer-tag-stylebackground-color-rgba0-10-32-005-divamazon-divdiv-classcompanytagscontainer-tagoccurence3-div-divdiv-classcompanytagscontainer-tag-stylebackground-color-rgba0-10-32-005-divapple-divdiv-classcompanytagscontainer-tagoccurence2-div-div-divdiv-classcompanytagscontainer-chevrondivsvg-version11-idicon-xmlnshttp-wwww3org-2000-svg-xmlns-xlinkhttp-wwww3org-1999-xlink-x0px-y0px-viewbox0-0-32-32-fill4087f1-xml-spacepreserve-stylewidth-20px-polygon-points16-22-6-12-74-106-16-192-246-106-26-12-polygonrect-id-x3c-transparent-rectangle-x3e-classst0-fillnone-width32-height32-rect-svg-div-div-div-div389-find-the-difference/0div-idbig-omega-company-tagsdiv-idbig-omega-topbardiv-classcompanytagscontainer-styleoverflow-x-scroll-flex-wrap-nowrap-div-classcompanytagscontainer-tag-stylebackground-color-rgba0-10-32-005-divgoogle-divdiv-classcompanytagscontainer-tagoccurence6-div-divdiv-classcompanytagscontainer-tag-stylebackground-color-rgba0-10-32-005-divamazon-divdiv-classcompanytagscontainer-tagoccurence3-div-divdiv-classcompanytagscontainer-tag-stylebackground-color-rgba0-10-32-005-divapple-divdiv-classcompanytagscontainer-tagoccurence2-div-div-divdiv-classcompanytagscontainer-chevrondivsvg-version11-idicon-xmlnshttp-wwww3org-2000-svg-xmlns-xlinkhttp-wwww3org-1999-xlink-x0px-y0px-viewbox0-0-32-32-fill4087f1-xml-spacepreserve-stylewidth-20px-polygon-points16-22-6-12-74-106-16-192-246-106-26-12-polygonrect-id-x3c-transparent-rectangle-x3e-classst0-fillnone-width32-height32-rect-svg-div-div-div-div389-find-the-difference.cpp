class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> s1,t1;
        for(int i=0;i<s.length();i++)
        {
            s1[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            t1[t[i]]++;
        }
        char c;
        for(auto it=t1.begin();it!=t1.end();it++)
        {
            if(s1.find(it->first)==s1.end() || s1[it->first]!=it->second)
            {
                c = it->first;
            }
        }
        return c;
    }
};