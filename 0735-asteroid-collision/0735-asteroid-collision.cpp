class Solution {
public:
    vector<int> asteroidCollision(vector<int>& s) {
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if(st.top()<0 || s[i]>0)
                {
                    st.push(s[i]);
                }
                else
                {
                    while(!st.empty() && st.top()>0 && st.top()<abs(s[i]))
                    {
                        st.pop();
                    }
                    if(st.empty())
                    {
                        st.push(s[i]);
                    }
                    else
                    {
                        if(st.top()==abs(s[i]))
                        {
                            st.pop();
                        }
                        else if(st.top()<0)
                        {
                            st.push(s[i]);
                        }
                    }
                }
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};