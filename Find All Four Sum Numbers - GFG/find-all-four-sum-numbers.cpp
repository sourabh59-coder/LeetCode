//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        set<vector<int>> st;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int l = j+1, r = n-1;
                while(l<r)
                {
                    if(arr[i]+arr[j]+arr[l]+arr[r]==k)
                    {
                        st.insert({arr[i],arr[j],arr[l],arr[r]});
                        l++;
                    }
                    else if(arr[i]+arr[j]+arr[l]+arr[r]<k)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it=st.begin();it!=st.end();it++)
        {
            ans.push_back(*it);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends