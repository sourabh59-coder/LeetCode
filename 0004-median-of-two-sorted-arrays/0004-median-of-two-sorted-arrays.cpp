class Solution {
public:
    double kthTerm(vector<int> v1,vector<int> v2,int n,int m,int k,int tot)
    {
        if(n>m) return kthTerm(v2,v1,m,n,k,tot);
        
        int l = max(0,k-m);
        
        int r = min(k,n);
        
        while(l<=r)
        {
            int mid1 = l + (r-l)/2;
            int mid2 = k-mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            
            if(mid1-1>=0)   l1 = v1[mid1-1];
            if(mid2-1>=0)   l2 = v2[mid2-1];
            if(mid1<n)      r1 = v1[mid1];
            if(mid2<m)      r2 = v2[mid2];
            
            if(l1<=r2 && l2<=r1)    
            {
                int a = max(l1,l2);
                int b = min(r1,r2);
                if(tot%2==0)
                {
                    double ans = (double)(a+b) / (double)2;
                    return ans;
                }
                else    return (double)a;
            }
            else if(l1>r2)  r = mid1-1;
            else            l = mid1+1;
        }
        
        return (double)-1;
    }
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int tot = v1.size() + v2.size();
        if(tot==1)
        {
            if(v1.size()!=0)    return v1[0];
            else                return v2[0];
        }
        int k = (tot+1) / 2;
        return kthTerm(v1,v2,v1.size(),v2.size(),k,tot);
    }
};