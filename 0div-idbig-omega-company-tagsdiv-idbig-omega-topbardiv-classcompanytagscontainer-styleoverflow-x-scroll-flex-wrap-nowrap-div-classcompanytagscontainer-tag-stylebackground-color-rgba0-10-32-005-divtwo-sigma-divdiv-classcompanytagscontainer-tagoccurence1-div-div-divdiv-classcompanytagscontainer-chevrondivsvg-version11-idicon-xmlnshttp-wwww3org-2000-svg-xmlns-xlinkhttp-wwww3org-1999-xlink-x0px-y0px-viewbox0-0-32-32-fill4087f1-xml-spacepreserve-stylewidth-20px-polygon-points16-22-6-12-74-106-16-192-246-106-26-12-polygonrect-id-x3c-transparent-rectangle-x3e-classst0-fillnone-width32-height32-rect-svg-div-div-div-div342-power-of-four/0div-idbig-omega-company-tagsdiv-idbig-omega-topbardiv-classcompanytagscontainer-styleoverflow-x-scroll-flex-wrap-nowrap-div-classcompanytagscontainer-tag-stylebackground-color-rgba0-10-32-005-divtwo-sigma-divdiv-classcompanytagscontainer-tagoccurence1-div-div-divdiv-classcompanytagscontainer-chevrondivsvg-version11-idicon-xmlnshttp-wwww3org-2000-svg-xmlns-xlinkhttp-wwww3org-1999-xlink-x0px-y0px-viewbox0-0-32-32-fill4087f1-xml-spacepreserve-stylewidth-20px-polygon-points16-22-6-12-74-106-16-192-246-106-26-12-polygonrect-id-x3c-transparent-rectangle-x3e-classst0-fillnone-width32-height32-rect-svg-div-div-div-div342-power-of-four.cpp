class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n<=0)
        {
            return false;
        }
        else if(n==1)
        {
            return true;
        }
        int k = log(n)/log(4);
        return (pow(4,k)==n);
    }
};