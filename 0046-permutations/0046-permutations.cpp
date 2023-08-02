class Solution {
public:
    void fun(vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp,unordered_set<int> &st,int ind)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i])==st.end())
            {
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                fun(nums,ans,temp,st,ind+1);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        unordered_set<int> st;
        fun(nums,ans,temp,st,0);
        return ans;
    }
};