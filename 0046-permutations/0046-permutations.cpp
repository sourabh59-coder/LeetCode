class Solution {
public:
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> ans;
        sort(v.begin(),v.end());
        
        
        do {
            // cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
            // vector<int> v1{v[0],v[1],v[2]};
            ans.push_back(v);
        } while (next_permutation(v.begin(),v.end()));
        
        return ans;
    }
};