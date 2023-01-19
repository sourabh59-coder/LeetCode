//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool comp(vector<int> &a,vector<int> &b)
{
    if(a[0]<b[0])
    {
        return true;
    }
    else if(a[0]==b[0])
    {
        if(a[1]>b[1])
        {
            return true;
        }
        else if(a[1]==b[1])
        {
            if(a[2]<b[2])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
class Solution{
    public:
    void customSort (int phy[], int chem[], int math[], int N)
    {
        vector<vector<int>> v;
        for(int i=0;i<N;i++)
        {
            vector<int> p{phy[i],chem[i],math[i]};
            v.push_back(p);
        }
        
        sort(v.begin(),v.end(),comp);
        
        for(int i=0;i<N;i++)
        {
            phy[i] = v[i][0];
            chem[i] = v[i][1];
            math[i] = v[i][2];
        }
    } 
};

//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int phy[n];
		int chem[n];
		int math[n];
		for (int i = 0; i < n; ++i)
			cin >> phy[i] >> chem[i] >> math[i];
        Solution ob;
		ob.customSort (phy, chem, math, n);
		for (int i = 0; i < n; ++i)
			cout << phy[i] << " " << chem[i] << " " << math[i] << endl; 
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends