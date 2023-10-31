class Solution {
public:
    vector<int> findArray(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n);
        
        ans[0] = v[0];
        
        int val = ans[0];
        
        for(int i=1;i<n;i++)
        {
            val = v[i]^v[i-1];
            
            ans[i] = val;
        }
        
        return ans;
    }
};