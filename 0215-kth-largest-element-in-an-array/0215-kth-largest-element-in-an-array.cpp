class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> qe;
        for(int i=0;i<nums.size();i++)
        {
            if(qe.size()<k)
            {
                qe.push(nums[i]);
            }
            else
            {
                qe.push(nums[i]);
                qe.pop();
            }
        }

        int ans = qe.top();

        // while(!qe.empty())
        // {
        //     ans = qe.top();
        //     qe.pop();
        // }

        return ans;
    }
};