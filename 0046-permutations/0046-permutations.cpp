class Solution {
public:
    void fun(vector<int> &v,int n,vector<int> &temp,vector<vector<int>> &ans,vector<int> &vis)
    {
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                temp.push_back(v[i]);
                fun(v,n,temp,ans,vis);
                temp.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(n,0);
        fun(v,n,temp,ans,vis);
        return ans;
    }
};