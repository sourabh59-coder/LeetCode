class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int k) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        long long n = v.size();
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<=(n-4);i++)
        {
            for(int j=i+1;j<=(n-3);j++)
            {
                long long l = (j+1);
                long long r = (n-1);
                
                while(l<r)
                {
                    long long val = (long long)(v[i])+(long long)(v[j])+(long long)(v[l])+(long long)(v[r]);
                    if(val==k)
                    {
                        st.insert({v[i],v[j],v[l],v[r]});
                        l++;
                    }
                    else if(val>k)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
        }
        
        for(auto it=st.begin();it!=st.end();it++)
        {
            ans.push_back(*it);
        }
        
        return ans;
    }
};