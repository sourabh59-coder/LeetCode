class Solution {
public:
    bool binarySearch(vector<int> arr, int l, int r, int x)
    {
            if (r >= l) {
                int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                return true;
 
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
 
            return binarySearch(arr, mid + 1, r, x);
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& v, int k) {
        bool ans = false;
        for(int i=0;i<v.size();i++)
        {
            if(binarySearch(v[i],0,v[i].size()-1,k))
            {
                ans = true;
                break;
            }
        }
        return ans;
    }
};