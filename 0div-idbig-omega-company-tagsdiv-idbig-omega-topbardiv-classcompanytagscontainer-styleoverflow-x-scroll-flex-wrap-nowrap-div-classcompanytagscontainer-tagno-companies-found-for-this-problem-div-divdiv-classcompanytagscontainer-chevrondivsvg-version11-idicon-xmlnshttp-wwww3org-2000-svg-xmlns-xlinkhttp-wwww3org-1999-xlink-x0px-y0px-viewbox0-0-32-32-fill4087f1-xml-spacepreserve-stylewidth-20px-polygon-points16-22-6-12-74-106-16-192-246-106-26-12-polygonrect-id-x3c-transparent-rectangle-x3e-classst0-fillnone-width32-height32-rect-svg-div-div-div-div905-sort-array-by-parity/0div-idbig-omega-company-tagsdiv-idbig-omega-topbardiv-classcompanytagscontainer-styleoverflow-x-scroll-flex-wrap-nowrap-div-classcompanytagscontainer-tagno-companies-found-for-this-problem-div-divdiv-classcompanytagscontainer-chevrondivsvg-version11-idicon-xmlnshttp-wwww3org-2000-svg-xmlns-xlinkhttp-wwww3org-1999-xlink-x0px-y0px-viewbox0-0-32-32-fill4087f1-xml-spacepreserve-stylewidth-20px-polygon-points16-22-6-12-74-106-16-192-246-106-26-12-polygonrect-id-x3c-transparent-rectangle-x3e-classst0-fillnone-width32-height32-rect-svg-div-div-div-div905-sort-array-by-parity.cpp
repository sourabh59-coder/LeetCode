class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& v) {
        vector<int> e,o;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]%2==0)
            {
                e.push_back(v[i]);
            }
            else
            {
                o.push_back(v[i]);
            }
        }
        e.insert(e.end(), o.begin(), o.end());
        return e;
    }
};