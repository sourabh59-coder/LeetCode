class Solution {
public:
    vector<int> NSL(vector<int> v)
    {
        stack<pair<int,int>> st;
        vector<int> ans;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                if(st.top().second < v[i])
                {
                    ans.push_back(st.top().first);
                }
                else
                {
                    while(!st.empty() && st.top().second >= v[i])
                    {
                        st.pop();
                    }
                    
                    if(st.empty())
                    {
                        ans.push_back(-1);
                    }
                    else
                    {
                        ans.push_back(st.top().first);
                    }
                }
            }
            st.push({i,v[i]});
        }
        
        return ans;
    }
    
    vector<int> NSR(vector<int> v)
    {
        stack<pair<int,int>> st;
        vector<int> ans;
        int n = v.size();
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                ans.push_back(n);
            }
            else
            {
                if(st.top().second < v[i])
                {
                    ans.push_back(st.top().first);
                }
                else
                {
                    while(!st.empty() && st.top().second >= v[i])
                    {
                        st.pop();
                    }
                    
                    if(st.empty())
                    {
                        ans.push_back(n);
                    }
                    else
                    {
                        ans.push_back(st.top().first);
                    }
                }
            }
            st.push({i,v[i]});
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    int largestRectangleArea(vector<int>& v) {
        int ans = 0;
        
        vector<int> lv = NSL(v);
        vector<int> rv = NSR(v);
        
        for(int i=0;i<v.size();i++)
        {
            ans = max(ans,(v[i]*(rv[i]-lv[i]-1)));
        }
        
        return ans;
    }
};