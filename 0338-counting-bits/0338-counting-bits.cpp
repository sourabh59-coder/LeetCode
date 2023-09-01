class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0 ; i<=n; i++)
        {
            int count=0;
            int k = i;
            // while(k)
            // {
            //     if((k&1)==1)
            //     {
            //         count++;
            //     } 
            //     k = k/2;
            // }
            for(int j=0;j<32;j++)
            {
                int mask = 1<<j;
                if(k&mask)
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
