class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        multiset<int> st;
        for(int i=0;i<k;i++)
        {
            st.insert(v[i]);
        }
        
        vector<int> ans;
        ans.push_back(*st.rbegin());
        
        int i = 0, j = k;
        
        while(j!=v.size())
        {
            st.insert(v[j++]);
            st.erase(st.find(v[i++]));
            ans.push_back(*st.rbegin());
        }
        
        return ans;
    }
};