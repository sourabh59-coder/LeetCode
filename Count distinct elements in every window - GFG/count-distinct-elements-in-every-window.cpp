//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int v[], int n, int k)
    {
        //code here.
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++)
        {
            mp[v[i]]++;
        }
        vector<int> ans;
        ans.push_back(mp.size());
        for(int i=0;i<n-k;i++)
        {
            mp[v[i+k]]++;
            mp[v[i]]--;
            if(mp[v[i]]==0)
            {
                mp.erase(v[i]);
            }
            ans.push_back(mp.size());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends