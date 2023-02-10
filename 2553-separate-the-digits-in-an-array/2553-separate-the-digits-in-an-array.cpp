class Solution {
public:
    vector<int> separateDigits(vector<int>& v) {
        vector<int> ans;
        for(int i=0;i<v.size();i++)
        {
            stack<int> st;
            // st.clear();
            int n = v[i];
            while(n)
            {
                int rem = n%10;
                st.push(rem);
                n = n/10;
            }
            
            while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};