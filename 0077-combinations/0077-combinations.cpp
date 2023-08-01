class Solution {
public:
    void fun(int n,int k,int ind,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        if(ind>n)   return;
        
        temp.push_back(ind);
        fun(n,k,ind+1,ans,temp);
        temp.pop_back();
        fun(n,k,ind+1,ans,temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(n,k,1,ans,temp);
        return ans;
    }
};