class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
    
        int ans = 0;
        set<int> st;

        int i=0,j=0;

        while(j!=n)
        {
            if(st.find(s[j])==st.end())
            {
                st.insert(s[j]);
                ans = max(ans,j-i+1);
                j++;
            }
            else
            {
                while(s[i]!=s[j])
                {
                    st.erase(s[i]);
                    i++;
                }
                st.erase(s[i]);
                i++;
                st.insert(s[j]);
                j++;
            }
        }

        return ans;
    }
};