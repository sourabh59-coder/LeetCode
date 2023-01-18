class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        long long prod = 1;
        int zero = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=0)
            {
                prod *= v[i];
            }
            else
            {
                zero++;
            }
        }
        if(zero>1)
        {
            vector<int> ans(v.size(),0);
            return ans;
        }
        else if(zero==1)
        {
            vector<int> ans(v.size());
            for(int i=0;i<v.size();i++)
            {
                if(v[i]==0)
                {
                    ans[i] = prod;
                }
                else
                {
                    ans[i] = 0;
                }
            }
            return ans;
        }
        else
        {
            vector<int> ans(v.size());
            for(int i=0;i<v.size();i++)
            {
                int val = prod/v[i];
                ans[i] = val;
            }
            return ans;
        }
        return v;
    }
};