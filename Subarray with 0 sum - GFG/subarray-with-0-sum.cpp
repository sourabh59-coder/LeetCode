//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int v[], int n)
    {
        for(int i=1;i<n;i++)
        {
            v[i] += v[i-1];
        }
        
        // 4 6 3 4 10
        
        unordered_set<int> st;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                return true;
            }
            if(st.find(v[i])==st.end())
            {
                st.insert(v[i]);
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends