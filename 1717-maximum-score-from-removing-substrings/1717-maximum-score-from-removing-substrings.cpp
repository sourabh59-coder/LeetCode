class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int n = s.length();
        int ans = 0;
        
        // Define the higher and lower gain pairs
        char highFirst = (x >= y) ? 'a' : 'b';
        char highSecond = (x >= y) ? 'b' : 'a';
        int highGain = max(x, y);
        int lowGain = min(x, y);
        
        char lowFirst = (x >= y) ? 'b' : 'a';
        char lowSecond = (x >= y) ? 'a' : 'b';

        // Process high gain pairs first
        for (char c : s) {
            if (!st.empty() && st.top() == highFirst && c == highSecond) {
                ans += highGain;
                st.pop();
            } else {
                st.push(c);
            }
        }

        // Collect remaining characters in a new string for the low gain pair processing
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        // Process low gain pairs
        for (char c : remaining) {
            if (!st.empty() && st.top() == lowFirst && c == lowSecond) {
                ans += lowGain;
                st.pop();
            } else {
                st.push(c);
            }
        }

        return ans;
    }
};
