class Solution {
public:
    long long m = 1e9+7;
    long long addModulo(long long a, long long b){ return ((a%m + b%m) + m)%m;}
    int countHomogenous(string s) {
        long long ans = 0;
        for(int i = 0; i < s.size(); i++){
            int j = i+1;
            long long cnt = 1;
            while(j < s.size() && s[i] == s[j]){
                cnt++;j++;
            }
            if(cnt % 2 == 0){
                long long t = (cnt/2)*(cnt+1);
                ans = addModulo(ans,t);
            }
            else {
                long long t = ((cnt+1)/2)*cnt;
                ans = addModulo(ans,t);
            }
            i = j-1;
        }
        return ans;
    }
};