class Solution {
public:
    int countOdds(int a, int b) {
        int k;
        if(a%2==0 && b%2==0)
        {
            k = (b-a)/2;
        }
        else if(a%2!=0 && b%2!=0)
        {
            k = ((b-a)/2)+1;
        }
        else
        {
            k = ((b-a)/2)+1;
        }
        return k;
    }
};