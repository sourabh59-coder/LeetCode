class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int ans = 0;
        int n = time.size();
        for(int i=0;i<n-1;i++)
        {
            if(colors[i]==colors[i+1])
            {
                if(time[i]<time[i+1])
                {
                    ans += time[i];
                }
                else
                {
                    ans += time[i+1];
                    time[i+1] = time[i];
                }
            }
        }
        
        return ans;
    }
};