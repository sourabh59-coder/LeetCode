class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n = v.size();
        if(n==1)    return;
        int i = 0, j = 1;
        while(i<n && j<n)
        {
            while(i<n && v[i]!=0)   i++;
            if(j<i)     j = i+1;
            while(j<n && v[j]==0)   j++;
            if(i<n && j<n && v[i]==0 && v[j]!=0)
            {
                swap(v[i],v[j]);
                i++;
                j++;
            }
        }   
    }
};