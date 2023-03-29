class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(),v.end());
        int ans = 0;
        int n = v.size();
        // int k = 0;
        for(int i=0;i<n;i++)
        {
            int k = 1;
            int sum = 0;
            for(int j=i;j<n;j++)
            {
                sum += (k*v[j]);
                k++;
            }
            ans = max(sum,ans);
        }
        
        return ans;
    }
};