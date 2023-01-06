class Solution {
public:
    int maxIceCream(vector<int>& v, int k) {
        int ans = 0;
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++)
        {
            if(k>=v[i])
            {
                ans++;
                k -= v[i];
            }
            else
            {
                break;
            }
        }
        
        return ans;
    }
};