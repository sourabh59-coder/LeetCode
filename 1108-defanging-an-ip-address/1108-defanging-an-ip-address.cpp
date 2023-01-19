class Solution {
public:
    string defangIPaddr(string s) {
        string ans = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='.')
            {
                ans += "[.]";
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};