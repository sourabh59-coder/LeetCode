class Solution {
public:
    const int mod = 1e9+7;
    vector<pair<int,int>> moments = {{1,2},{2,1},{-1,2},{2,-1},{-2,1},{1,-2},{-2,-1},{-1,-2}};
    vector<vector<vector<int>>> dp;

    int fun(int i, int j, int n, vector<vector<int>> &check) {
        if (n == 0) return 1;

        if (dp[i][j][n] != -1) return dp[i][j][n];

        int ans = 0;

        for (auto moment : moments) {
            int x = moment.first + i;
            int y = moment.second + j;

            if (x >= 0 && x < check.size() && y >= 0 && y < check[0].size() && check[x][y]) {
                ans = (ans + fun(x, y, n - 1, check)) % mod;
            }
        }

        return dp[i][j][n] = ans % mod;
    }

    int knightDialer(int n) {
        vector<vector<int>> check = {{1,1,1}, {1,1,1}, {1,1,1}, {0,1,0}};
        dp = vector<vector<vector<int>>>(4, vector<vector<int>>(3, vector<int>(n + 1, -1)));

        int ans = 0;
        for (int i = 0; i < check.size(); i++) {
            for (int j = 0; j < check[0].size(); j++) {
                if (check[i][j]) {
                    ans = (ans + fun(i, j, n - 1, check)) % mod;
                }
            }
        }
        return ans;
    }
};
