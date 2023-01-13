class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        int n = num;
        
        while(n)
        {
            int rem = n%10;
            if(num%rem==0)
            {
                ans++;
            }
            n = n/10;
        }
        
        return ans;
    }
};