class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        vector<bool> check(100004,false);
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>=0 && v[i]<=100003)
            {
                check[v[i]] = true;
            }
        }
        for(int i=1;i<check.size();i++)
        {
            if(check[i]==false)
            {
                return i;
            }
        }
        return 0;
    }
};