class Solution {
public:
    int searchInsert(vector<int>& v, int k) {
        int ans = v.size();
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>=k)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};