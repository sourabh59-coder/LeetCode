class Solution {
public:
    void fun1(vector<int> v,int l,int r,int k,int &a)
    {
        while(l<=r)
        {
            int mid = (r-l)/2 + l;
            if(v[mid]==k)
            {
                a = mid;
                r = mid-1;
            }
            else if(v[mid]>k)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
    }
    void fun2(vector<int> v,int l,int r,int k,int &b)
    {
        while(l<=r)
        {
            int mid = (r-l)/2 + l;
            if(v[mid]==k)
            {
                b = mid;
                l = mid+1;
            }
            else if(v[mid]<k)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
    }
    vector<int> searchRange(vector<int>& v, int k) {
        int a = -1, b = -1;
        fun1(v,0,v.size()-1,k,a);
        fun2(v,0,v.size()-1,k,b);
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};