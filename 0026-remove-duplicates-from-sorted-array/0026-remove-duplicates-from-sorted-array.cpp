class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int i=0,j=1;
        while(j!=v.size())
        {
            if(v[j]!=v[i])
            {
                v[i+1] = v[j];
                i++;
            }
            j++;
        }
        return (i+1);
    }
};