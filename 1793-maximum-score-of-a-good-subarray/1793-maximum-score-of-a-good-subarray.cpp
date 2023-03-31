class Solution {
public:
    vector<int> NSR(vector<int> arr,int n)
{
	stack<pair<int,int> > st;
	vector<int> v;
	
	for(int i=n-1;i>=0;i--)
	{
		if(st.empty())
		{
			v.push_back(n);
		}
		else if(!st.empty() && st.top().second < arr[i])
		{
			v.push_back(st.top().first);
		}
		else if(!st.empty() && st.top().second >= arr[i])
		{
			while(!st.empty() && st.top().second >= arr[i])
			{
				st.pop();
			}
			if(st.empty())
			{
				v.push_back(n);
			}
			else
			{
				v.push_back(st.top().first);
			}
		}
		st.push({i,arr[i]});
	}
	
	reverse(v.begin(),v.end());
	return v;
}
vector<int> NSL(vector<int> arr,int n)
{
	stack<pair<int,int> > st;
	vector<int> v;
	
	for(int i=0;i<n;i++)
	{
		if(st.empty())
		{
			v.push_back(-1);
		}
		else if(!st.empty() && st.top().second < arr[i])
		{
			v.push_back(st.top().first);
		}
		else if(!st.empty() && st.top().second >= arr[i])
		{
			while(!st.empty() && st.top().second >= arr[i])
			{
				st.pop();
			}
			if(st.empty())
			{
				v.push_back(-1);
			}
			else
			{
				v.push_back(st.top().first);
			}
		}
		st.push({i,arr[i]});
	}
	
	return v;
}
int MaxAreaOfHistogram(vector<int> arr,int n,int k)
{
	vector<int> vr = NSR(arr,n);
	vector<int> vl = NSL(arr,n);
	
	// vector<int> vf;
    int ans = 0;
    // vf.push_back(0);
	
	for(int i=0;i<vr.size();i++)
	{
		// vf.push_back((vr[i]-vl[i]-1)*arr[i]);
        if(vl[i]<k && vr[i]>k)
        {
            ans = max(ans,((vr[i]-vl[i]-1)*arr[i]));
        }
	}
	
	// sort(vf.begin(),vf.end());
	
	return ans;
}
    int maximumScore(vector<int>& nums, int k) {
        return MaxAreaOfHistogram(nums,nums.size(),k);
    }
};