class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool ans = true;
        int j = 0;
        for(int i=0;i<t.length();i++)
        {
            if(s[j]==t[i])
            {
                j++;
            }
            if(j==s.length())
            {
                ans = true;
            }
        }
        
        if(j!=s.length())
        {
            ans = false;
        }
        
        return ans;
    }
};