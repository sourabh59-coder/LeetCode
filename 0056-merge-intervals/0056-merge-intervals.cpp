class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        stack<vector<int>> st;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            if(st.empty())
            {
                st.push(v[i]);
            }
            else
            {
                if(st.top()[1]<v[i][0])
                {
                    st.push(v[i]);
                }
                else
                {
                    vector<int> v1 = st.top();
                    st.pop();
                    
                    v1[1] = max(v1[1],v[i][1]);
                    st.push(v1);
                }
            }
        }
        
        vector<vector<int>> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};