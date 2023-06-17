class Solution {
public:
    void Fun(vector<int> &nums,int n,int i,set<vector<int>> &st,vector<int> v)
    {
        if(i==n)
        {
            st.insert(v);
            return;
        }
        
        v.push_back(nums[i]);
        Fun(nums,n,i+1,st,v);
        
        v.pop_back();
        Fun(nums,n,i+1,st,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        
        vector<int> v;
        Fun(nums,nums.size(),0,st,v);
        
        for(auto it=st.begin();it!=st.end();it++)
        {
            ans.push_back(*it);
        }
        
        return ans;
    }
};