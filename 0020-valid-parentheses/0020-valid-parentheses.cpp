class Solution {
public:
    bool isValid(string s) {
        bool ans = true;
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                else 
                {
                    if(s[i]==']' && st.top()!='[')
                    {
                        return false;
                    }
                    else if(s[i]=='}' && st.top()!='{')
                    {
                        return false;
                    }
                    else if(s[i]==')' && st.top()!='(')
                    {
                        return false;
                    }
                    else
                    {
                        st.pop();
                    }
                }
            }
        }
        
        if(!st.empty())
        {
            return false;
        }
        
        return true;
    }
};