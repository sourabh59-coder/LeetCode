class Solution {
public:
    long long maxKelements(vector<int>& v, int k) {
        long long ans = 0;
        priority_queue<int> qe;
        for(int i=0;i<v.size();i++)
        {
            qe.push(v[i]);
        }
        while(k--)
        {
            int val = qe.top();
            qe.pop();
            ans += val;
            val = ceil((double)val/3);
            qe.push(val);
        }
        
        return ans;
    }
};