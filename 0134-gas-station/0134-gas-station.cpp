class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> v(gas.size());
        
        int sum = 0;
        for(int i=0;i<gas.size();i++)
        {
            v[i] = gas[i]-cost[i];
            sum += v[i];
        }
        
        if(sum<0)
        {
            return-1;
        }
        
        int start = 0;
        int csum = 0;
        for(int i=0;i<gas.size();i++)
        {
            csum += v[i];
            
            if(csum<0)
            {
                start = i+1;
                
                csum = 0;
            }
        }
        
        return start;
    }
};