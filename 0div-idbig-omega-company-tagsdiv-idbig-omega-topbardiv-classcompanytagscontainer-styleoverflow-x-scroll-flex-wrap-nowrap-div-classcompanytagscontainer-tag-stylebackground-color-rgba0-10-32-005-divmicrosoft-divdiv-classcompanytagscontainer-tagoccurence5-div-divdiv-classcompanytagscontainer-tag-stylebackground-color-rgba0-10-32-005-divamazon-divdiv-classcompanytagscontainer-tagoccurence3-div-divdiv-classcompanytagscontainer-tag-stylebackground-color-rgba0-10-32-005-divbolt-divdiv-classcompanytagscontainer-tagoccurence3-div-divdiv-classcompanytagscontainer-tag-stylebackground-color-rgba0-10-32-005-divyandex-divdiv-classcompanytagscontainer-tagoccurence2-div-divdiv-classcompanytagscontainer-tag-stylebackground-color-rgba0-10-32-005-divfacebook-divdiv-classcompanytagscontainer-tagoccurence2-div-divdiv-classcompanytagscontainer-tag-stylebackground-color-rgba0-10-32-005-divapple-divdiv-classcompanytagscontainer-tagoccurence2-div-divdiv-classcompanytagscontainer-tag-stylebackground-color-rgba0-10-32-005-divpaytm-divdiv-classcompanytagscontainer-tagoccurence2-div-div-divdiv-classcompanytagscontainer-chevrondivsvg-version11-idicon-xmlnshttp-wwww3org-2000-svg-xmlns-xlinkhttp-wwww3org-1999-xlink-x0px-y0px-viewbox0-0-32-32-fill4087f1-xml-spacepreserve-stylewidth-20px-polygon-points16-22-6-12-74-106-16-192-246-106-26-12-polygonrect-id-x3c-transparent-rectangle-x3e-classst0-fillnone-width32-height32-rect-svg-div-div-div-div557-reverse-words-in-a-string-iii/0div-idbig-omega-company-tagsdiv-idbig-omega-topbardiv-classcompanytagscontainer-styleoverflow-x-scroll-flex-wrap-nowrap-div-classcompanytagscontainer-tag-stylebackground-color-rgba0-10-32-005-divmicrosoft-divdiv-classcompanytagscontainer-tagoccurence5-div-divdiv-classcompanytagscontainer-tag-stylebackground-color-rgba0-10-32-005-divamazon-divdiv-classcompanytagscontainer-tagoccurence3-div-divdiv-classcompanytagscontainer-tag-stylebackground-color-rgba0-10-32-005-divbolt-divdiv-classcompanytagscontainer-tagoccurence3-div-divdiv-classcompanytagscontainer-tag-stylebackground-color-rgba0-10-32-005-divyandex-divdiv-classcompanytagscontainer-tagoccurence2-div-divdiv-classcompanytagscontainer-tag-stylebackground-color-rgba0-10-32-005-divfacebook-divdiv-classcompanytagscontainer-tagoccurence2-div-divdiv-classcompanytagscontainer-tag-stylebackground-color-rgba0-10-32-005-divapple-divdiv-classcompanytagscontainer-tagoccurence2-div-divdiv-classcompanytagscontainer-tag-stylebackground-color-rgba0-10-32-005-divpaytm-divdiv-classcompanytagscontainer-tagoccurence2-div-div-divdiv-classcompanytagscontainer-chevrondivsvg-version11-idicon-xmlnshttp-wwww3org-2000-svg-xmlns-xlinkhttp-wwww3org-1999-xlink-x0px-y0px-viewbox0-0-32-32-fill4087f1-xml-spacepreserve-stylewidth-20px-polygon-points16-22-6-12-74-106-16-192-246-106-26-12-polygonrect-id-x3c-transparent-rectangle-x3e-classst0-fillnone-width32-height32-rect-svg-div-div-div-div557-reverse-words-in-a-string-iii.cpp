class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.length();
        for(int j=0;j<n;j++)
        {
            if(s[j]==' ')
            {
                reverse(s.begin()+i,s.begin()+j);
                i = j+1;
            }
            if(j==(n-1))
            {
                reverse(s.begin()+i,s.end());
            }
        }
        return s;
    }
};