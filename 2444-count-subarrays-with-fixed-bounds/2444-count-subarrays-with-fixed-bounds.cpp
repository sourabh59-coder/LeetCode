class Solution {
public:
    long long countSubarrays(vector<int>& v, int minK, int maxK) {
        int state = 0, minInd = 0, maxInd = 0;
        long long int ans = 0;
        bool minF = false, maxF = false;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i]<minK || v[i]>maxK)
            {
                state = i+1;
                minF = false;
                maxF = false;
            }
            
            if(v[i]==maxK)
            {
                maxInd = i;
                maxF =true;
            }
            
            if(v[i]==minK)
            {
                minInd = i;
                minF = true;
            }
            
            if(minF && maxF)
            {
                ans += (min(maxInd,minInd) - state + 1);
            }
        }
        return ans;
    }
};