class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0) 
        {
            if(nums1==nums2) return 0; 
            return -1;
        }
        
        long long p_diff=0, n_diff=0; 
        
        for(int i=0; i<nums1.size(); i++)
        {
            if(nums1[i] >= nums2[i])
            {
                if((nums1[i]-nums2[i])%k==0) 
                    p_diff += nums1[i]-nums2[i];
                else
                    return -1;
            } 
            else 
            {
                if((nums2[i]-nums1[i])%k==0)
                    n_diff += nums2[i]-nums1[i];
                else
                    return -1;
            }
        }
        
        long long ans=-1;
        if(p_diff-n_diff==0) ans = (p_diff/k);
        return ans;
    }
};