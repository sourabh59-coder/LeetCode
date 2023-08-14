class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        sort(v.begin(),v.end(),greater<int>());
        return v[k-1];
    }
};