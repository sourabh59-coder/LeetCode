class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int> maxQ;
        priority_queue<int, vector<int>, greater<int>> minQ;
        
        int n = weights.size();
        for (int i = 0; i < n - 1; i++) {
            maxQ.push(weights[i] + weights[i + 1]);
            if (maxQ.size() == k) {
                maxQ.pop();
            }
            
            minQ.push(weights[i] + weights[i + 1]);
            if (minQ.size() == k) {
                minQ.pop();
            }
        }
        
        
        long long diff = 0;
        while (!minQ.empty()) {
            diff += minQ.top() - maxQ.top();
            minQ.pop(); maxQ.pop();
        }
        
        return diff;
    }
};