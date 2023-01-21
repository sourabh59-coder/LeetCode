class Solution {
public:
    int getCommon(vector<int>& v1, vector<int>& v2) {
        set<int> st;
        for(int i=0;i<v1.size();i++)
        {
            st.insert(v1[i]);
        }
        int ans = INT_MAX;
        for(int i=0;i<v2.size();i++)
        {
            if(st.find(v2[i])!=st.end())
            {
                ans = min(ans,v2[i]);
            }
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};