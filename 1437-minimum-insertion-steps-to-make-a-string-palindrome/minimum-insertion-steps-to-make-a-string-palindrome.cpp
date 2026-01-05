class Solution {
public:
    int minInsertions(string str) {
        int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int s = 0; s + len - 1 < n; s++) {
            int e = s + len - 1;

            if (str[s] == str[e]) {
                dp[s][e] = dp[s + 1][e - 1];
            } else {
                dp[s][e] = 1 + min(dp[s + 1][e], dp[s][e - 1]);
            }
        }
    }

    return dp[0][n - 1];
    }
};