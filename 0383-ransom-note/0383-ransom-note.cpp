class Solution {
public:
    bool canConstruct(string r, string m) {
        map<char,int> r1,m1;
        for(int i=0;i<r.length();i++)
        {
            r1[r[i]]++;
        }
        for(int i=0;i<m.length();i++)
        {
            m1[m[i]]++;
        }
        bool ans = true;
        
        for(auto it=r1.begin();it!=r1.end();it++)
        {
            if(m1[it->first]<it->second)
            {
                ans = false;
                break;
            }
        }
        
        return ans;
    }
};