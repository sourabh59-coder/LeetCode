class Solution {
public:
    void fun(vector<int> v,set<vector<int>> &st,int ind,vector<int> &p)
    {
        if(ind==v.size())
        {
            if(p.size()>1)
            {
                st.insert(p);
            }
            
            return;
        }
        fun(v,st,ind+1,p);
            
        if(p.empty() || v[ind]>=p.back())
        {
            p.push_back(v[ind]);
            fun(v,st,ind+1,p);
            p.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& v) {
        set<vector<int>> st;
        
        vector<int> p;
        fun(v,st,0,p);
        
        vector<vector<int>> ans;
        for(auto it=st.begin();it!=st.end();it++)
        {
            ans.push_back(*it);
        }
        return ans;
    }
};