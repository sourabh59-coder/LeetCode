class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        
        stack<vector<int>> st;
        
        for(int i=0;i<v.size();i++)
        {
            if(st.empty())
            {
                st.push(v[i]);
            }
            else
            {
                if(st.top()[1]>=v[i][0])
                {
                    vector<int> p = st.top();
                    st.pop();
                    
                    p[1] = min(p[1],v[i][1]);
                    st.push(p);
                }
                else
                {
                    st.push(v[i]);
                }
            }
        }
        
        return st.size();
    }
};