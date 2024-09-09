class Solution {
public:
    vector<int> singleNumber(vector<int>& v) {
        long long n = 0;
        for(auto it : v) {
            n ^= it;  
        }

        
        long long set_bit_left = (n&(n-1))^n;

        long long a = 0, b = 0;
        for(auto it : v) {
            if((set_bit_left & it) != 0) {
                a ^= it;  
            } else {
                b ^= it;  
            }
        }

        if(a < b) {
            return {(int)a, (int)b};
        }
        return {(int)b, (int)a};
    }
};
