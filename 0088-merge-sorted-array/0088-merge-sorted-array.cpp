class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        int j = m-1;
        int b = v1.size()-1;
        int i = n-1;
        
        while(i!=-1 || j!=-1)
        {
            // int val = INT_MIN;
            if(i!=-1 && j!=-1)
            {
                if(v2[i]>v1[j])
                {
                    v1[b--] = v2[i--];
                }
                else
                {
                    v1[b--] = v1[j--];
                }
            }
            else if(i!=-1)
            {
                v1[b--] = v2[i--];
            }
            else
            {
                v1[b--] = v1[j--];
            }
        }
    }
};