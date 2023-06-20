class Solution {
public:
    void fun(vector<int> v,unordered_map<int,int> mp,vector<int> &ans)
    {
        stack<int> st;
        int n = v.size();
        
        for(int i=n-1;i>=0;i--)
        {
            if(mp.find(v[i])!=mp.end())
            {
                if(st.empty())
                {
                    ans[mp[v[i]]] = -1;
                }
                else
                {
                    if(st.top() > v[i])
                    {
                        ans[mp[v[i]]] = st.top();
                    }
                    else
                    {
                        while(!st.empty() && st.top() <= v[i])
                        {
                            st.pop();
                        }
                        if(st.empty())
                        {
                            ans[mp[v[i]]] = -1;
                        }
                        else
                        {
                            ans[mp[v[i]]] = st.top();
                        }
                    }
                }
            }
            
            st.push(v[i]);
        }
    }
    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2) {
        vector<int> ans(v1.size(),0);
        unordered_map<int,int> mp;
        for(int i=0;i<v1.size();i++)
        {
            mp[v1[i]] = i;
        }
        fun(v2,mp,ans);
        return ans;
    }
};