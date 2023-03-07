class Solution {
public:
    int mySqrt(int x) {
        long long l = 0;
        long long r = x;
        long long res = -1;
        while(l<=r)
        {
            long long mid = l + (r-l)/2;
            if(mid*mid==x)
            {
                res = mid;
                break;
            }
            else if(mid*mid>x)
            {
                r = mid-1;
            }
            else
            {
                res = mid;
                l = mid+1;
            }
        }
        
        return res;
    }
};