class Solution {
public:
    int kItemsWithMaximumSum(int one, int zero, int negone, int k) {
        int ans = 0;
        while(one && k)
        {
            ans++;
            one--;
            k--;
        }
        
        while(zero && k)
        {
            zero--;
            k--;
        }
        
        while(negone && k)
        {
            ans--;
            negone--;
            k--;
        }
        
        return ans;
    }
};