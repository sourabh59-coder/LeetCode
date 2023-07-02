class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        bool flag = true;
        int size = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=threshold)
            {
                if(flag)
                {
                    if(nums[i]%2==0)
                    {
                        size++;
                        // ans = max(ans,size);
                        flag = false;
                    }
                    else
                    {
                        size = 0;
                    }
                }
                else
                {
                    if(nums[i]%2!=0)
                    {
                        size++;
                        
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                        size = 1;
                    }
                }
                ans = max(ans,size);
            }
            else
            {
                size = 0;
                flag = true;
            }
        }
        return ans;
    }
};