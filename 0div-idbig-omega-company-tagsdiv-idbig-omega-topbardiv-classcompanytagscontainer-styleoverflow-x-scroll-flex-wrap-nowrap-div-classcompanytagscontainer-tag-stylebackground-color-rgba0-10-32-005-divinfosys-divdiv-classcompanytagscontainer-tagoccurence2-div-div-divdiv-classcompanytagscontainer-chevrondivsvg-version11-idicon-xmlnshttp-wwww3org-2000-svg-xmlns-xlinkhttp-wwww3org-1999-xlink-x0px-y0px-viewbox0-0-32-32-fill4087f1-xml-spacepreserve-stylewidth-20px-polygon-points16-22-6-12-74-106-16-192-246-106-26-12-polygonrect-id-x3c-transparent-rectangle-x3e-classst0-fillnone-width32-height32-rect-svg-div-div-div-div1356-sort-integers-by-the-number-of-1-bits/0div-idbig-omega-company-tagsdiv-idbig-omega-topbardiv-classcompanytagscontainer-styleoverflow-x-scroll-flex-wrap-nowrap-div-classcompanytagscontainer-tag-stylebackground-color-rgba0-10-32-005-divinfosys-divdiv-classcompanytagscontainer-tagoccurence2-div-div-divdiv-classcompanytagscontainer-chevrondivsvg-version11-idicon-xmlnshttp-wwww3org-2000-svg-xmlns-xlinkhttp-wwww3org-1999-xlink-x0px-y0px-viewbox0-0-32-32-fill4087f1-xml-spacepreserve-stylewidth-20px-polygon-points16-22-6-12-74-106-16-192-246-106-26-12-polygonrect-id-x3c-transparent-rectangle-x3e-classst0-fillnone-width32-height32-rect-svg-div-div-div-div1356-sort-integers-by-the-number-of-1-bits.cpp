class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>> v;
       
        vector<int> ans;
        for(int i=0;i<n;i++)
            v.push_back(make_pair(__builtin_popcount(arr[i]),arr[i]));
        sort(v.begin(),v.end());
         int m=v.size();
        for(int i=0;i<m;i++)
            ans.push_back(v[i].second);
        return ans;
    }
};