class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        unordered_map<int,int> mp;
        int n = v.size();
        for(int i=0;i<v.size();i++)
        {
            mp[v[i]]++;
        }
        sort(v.begin(),v.end());
        set<vector<int>> st;
        
        for(int i=0;i<=(n-3);i++)
        {
            // int val = v[i];
            int l = (i+1), r = (n-1);
            while(l<r)
            {
                int val = (v[i]+v[l]+v[r]);
                if(val==0)
                {
                    st.insert({v[i],v[l],v[r]});
                    l++;
                }
                else if(val>0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        
        vector<vector<int>> ans;
        for(auto it=st.begin();it!=st.end();it++)
        {
            ans.push_back(*it);
        }
        
        return ans;
    }
};