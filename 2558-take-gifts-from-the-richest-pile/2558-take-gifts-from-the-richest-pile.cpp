class Solution {
public:
    long long pickGifts(vector<int>& v, int k) {
        long long int ans = 0;
        priority_queue<int> qe;
        for(int i=0;i<v.size();i++)
        {
            qe.push(v[i]);
        }
        while(k--)
        {
            int val = qe.top();
            qe.pop();
            
            val = sqrt(val);
            qe.push(val);
        }
        while(!qe.empty())
        {
            ans += qe.top();
            qe.pop();
        }
        return ans;
    }
};