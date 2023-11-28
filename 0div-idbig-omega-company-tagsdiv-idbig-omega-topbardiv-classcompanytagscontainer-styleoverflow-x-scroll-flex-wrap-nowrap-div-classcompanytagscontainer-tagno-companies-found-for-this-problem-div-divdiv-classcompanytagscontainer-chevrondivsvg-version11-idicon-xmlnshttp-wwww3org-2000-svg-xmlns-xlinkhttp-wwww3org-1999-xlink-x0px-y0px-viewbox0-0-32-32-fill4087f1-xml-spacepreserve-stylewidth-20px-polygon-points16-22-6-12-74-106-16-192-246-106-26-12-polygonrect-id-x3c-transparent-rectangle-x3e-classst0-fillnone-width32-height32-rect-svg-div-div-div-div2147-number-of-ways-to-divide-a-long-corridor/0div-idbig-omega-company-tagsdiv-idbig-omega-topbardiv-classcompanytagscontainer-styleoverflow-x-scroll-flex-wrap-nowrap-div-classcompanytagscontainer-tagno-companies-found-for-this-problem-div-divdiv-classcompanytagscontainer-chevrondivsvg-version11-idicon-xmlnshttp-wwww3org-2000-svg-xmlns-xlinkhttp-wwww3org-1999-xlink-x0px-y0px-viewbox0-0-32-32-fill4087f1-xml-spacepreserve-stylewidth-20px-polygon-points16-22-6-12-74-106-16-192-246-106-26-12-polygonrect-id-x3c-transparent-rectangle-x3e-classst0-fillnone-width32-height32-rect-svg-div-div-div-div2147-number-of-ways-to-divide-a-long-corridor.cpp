class Solution {
public:
    int numberOfWays(string corridor) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        // Store 1000000007 in a variable for convenience
        const int MOD = 1e9 + 7;

        // Initial values of three variables
        int zero = 0;
        int one = 0;
        int two = 1;

        // Compute using derived equations
        for (char thing : corridor) {
            if (thing == 'S') 
            {
                zero = one;
                swap(one, two);
            } 
            else 
            {
                two = (two + zero) % MOD;
            }
        }

        // Return the result
        return zero;
    }
};