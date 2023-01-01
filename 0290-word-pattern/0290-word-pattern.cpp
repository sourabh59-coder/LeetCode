class Solution {
public:
    bool wordPattern(string p, string s) {
        map<char,string> mp;
        map<string,char> mp1;
        vector<string> v;
        
        string s1 = "";
        
        for(int i=0;i<s.length();i++)
        {
            if(i==s.length()-1)
            {
                s1 += s[i];
                v.push_back(s1);
                s1 = "";
            }
            if(s[i]==' ')
            {
                v.push_back(s1);
                s1 = "";
            }
            else
            {
                s1 += s[i];
            }
        }
        
        // for(int i=0;i<v.size();i++)
        // {
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        // return true;
        
        if(v.size()!=p.size())
        {
            return false;
        }
        
        for(int i=0;i<p.size();i++)
        {
            if(mp.find(p[i])==mp.end() && mp1.find(v[i])==mp1.end())
            {
                mp[p[i]] = v[i];
                mp1[v[i]] = p[i];
            }
            else
            {
                if(mp[p[i]]!=v[i] || mp1[v[i]]!=p[i])
                {
                    return false;
                }
                else
                {
                    continue;
                }
            }
        }
        
        return true;
    }
};