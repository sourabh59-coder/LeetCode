class Solution {
public:
    bool isValid(string s) {
        bool ans = true;
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            else if(s[i]==']')
            {
                if(!st.empty() && st.top()=='[')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            else if(s[i]=='}')
            {
                if(!st.empty() && st.top()=='{')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    ans = false;
                    break;
                }
            }
        }
        
        if(!st.empty())
        {
            ans = false;
        }
        
        return ans;
    }
};