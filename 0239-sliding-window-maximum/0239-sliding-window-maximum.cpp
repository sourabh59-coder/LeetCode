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
        for(int i=0;i<v.size()-k;i++)
        {
            st.erase(st.find(v[i]));
            st.insert(v[i+k]);
            ans.push_back(*st.rbegin());
        }
        
        return ans;
    }
};