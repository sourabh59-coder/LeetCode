class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        std::vector<int> left(26, -1);
        std::vector<int> right(26, -1);

        int curr;
        for (int i = 0; i < s.length(); i++) {
            curr = s[i] - 'a';
            if (left[curr] == -1) {
                left[curr] = i;
            }
            right[curr] = i;
        }

        int ans = 0;
        std::vector<bool> count(26, false);
        for (int i = 0; i < 26; i++) {
            if (left[i] == -1) {
                continue;
            }
            std::fill(count.begin(), count.end(), false);
            for (int j = left[i] + 1; j < right[i]; j++) {
                if (!count[s[j] - 'a']) {
                    count[s[j] - 'a'] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};