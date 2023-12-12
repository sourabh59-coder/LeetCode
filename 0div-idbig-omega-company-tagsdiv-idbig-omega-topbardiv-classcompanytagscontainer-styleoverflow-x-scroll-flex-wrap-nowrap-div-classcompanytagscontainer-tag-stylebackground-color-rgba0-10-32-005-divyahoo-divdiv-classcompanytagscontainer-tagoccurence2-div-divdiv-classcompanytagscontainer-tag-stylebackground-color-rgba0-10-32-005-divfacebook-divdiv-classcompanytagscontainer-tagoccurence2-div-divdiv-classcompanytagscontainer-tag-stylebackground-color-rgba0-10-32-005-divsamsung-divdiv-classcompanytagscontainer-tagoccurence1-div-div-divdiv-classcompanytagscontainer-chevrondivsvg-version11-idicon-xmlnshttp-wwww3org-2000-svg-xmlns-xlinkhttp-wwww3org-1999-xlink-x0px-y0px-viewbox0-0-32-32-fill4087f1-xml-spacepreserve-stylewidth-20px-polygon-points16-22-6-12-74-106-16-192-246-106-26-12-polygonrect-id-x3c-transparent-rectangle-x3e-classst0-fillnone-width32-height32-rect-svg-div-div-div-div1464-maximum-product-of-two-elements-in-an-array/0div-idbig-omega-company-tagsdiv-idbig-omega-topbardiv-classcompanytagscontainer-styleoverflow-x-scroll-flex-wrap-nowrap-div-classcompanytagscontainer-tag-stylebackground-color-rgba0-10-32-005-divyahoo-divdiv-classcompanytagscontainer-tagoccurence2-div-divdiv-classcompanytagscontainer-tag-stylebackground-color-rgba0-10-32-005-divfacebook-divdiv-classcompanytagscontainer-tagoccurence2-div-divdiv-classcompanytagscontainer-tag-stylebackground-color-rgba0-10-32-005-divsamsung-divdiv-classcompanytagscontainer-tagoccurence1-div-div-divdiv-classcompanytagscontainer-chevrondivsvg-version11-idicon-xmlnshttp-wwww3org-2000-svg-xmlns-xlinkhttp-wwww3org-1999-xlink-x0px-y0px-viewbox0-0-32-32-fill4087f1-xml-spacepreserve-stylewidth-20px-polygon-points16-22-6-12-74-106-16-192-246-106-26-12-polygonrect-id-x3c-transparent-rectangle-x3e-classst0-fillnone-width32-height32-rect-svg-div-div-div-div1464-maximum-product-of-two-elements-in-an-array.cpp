class Solution {
public:
    int maxProduct(vector<int>& v) {
        sort(v.begin(),v.end());
        int a = v[v.size()-1]-1;
        int b = v[v.size()-2]-1;
        return (a*b);
    }
};