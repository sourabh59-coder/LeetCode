void primeFactors(int n,unordered_set<int> &st)
{
    int c=2;
    while(n>1)
    {
        if(n%c==0){
        // cout<<c<<" ";
            st.insert(c);
        n/=c;
        }
        else c++;
    }
}

class Solution {
public:
    int distinctPrimeFactors(vector<int>& v) {
        unordered_set<int> st;
        for(int i=0;i<v.size();i++)
        {
            primeFactors(v[i],st);
        }
        return st.size();
    }
};