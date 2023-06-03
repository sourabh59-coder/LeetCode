class Solution {
public:
    //            x y z a b c a b c b b   
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int ans = 0;
        int j=0;
        int i=0;
        for(i=0;i<s.length();i++)
        {
            if(st.find(s[i])==st.end())
            {
                st.insert(s[i]);
                int var = st.size();
                ans = max(ans,var);
            }
            else
            {
                while(s[j]!=s[i])
                {
                    st.erase(s[j]);
                    j++;
                }
                j++;
            }
        }
        int var = st.size();
        ans = max(ans,var);
        return ans;
    }
};