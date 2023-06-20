class Solution {
public:
    vector<int> getAverages(vector<int>& v, int k) {
        if((2*k+1) > v.size())
        {
            vector<int> an(v.size(),-1);
            return an;
        }
        int i = 0;
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(-1);
        }
        int j=0;
        long long sum = 0;
        for(j=0;j<(2*k+1);j++)
        {
            sum += v[j];
        }
        long long val = sum/(2*k+1);
        ans.push_back(val);
        while(j!=v.size())
        {
            sum += v[j]-v[i];
            val = sum/(2*k+1);
            ans.push_back(val);
            j++;
            i++;
        }
        for(int i=0;i<k;i++)
        {
            ans.push_back(-1);
        }
        return ans;
    }
};