class Solution {
public:
    // time/space: O(nlogn)/O(1)
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // sort the array to a non-decreasing order
        sort(arr.begin(), arr.end());

        // set the value of the first element as `1`
        arr[0] = 1;

        // iterate and make sure the rule (`abs(arr[i] - arr[i - 1]) <= 1`) meets
        int result = 1;
        for (auto& num : arr) result = min(result + 1, num);
        return result;
    }
};