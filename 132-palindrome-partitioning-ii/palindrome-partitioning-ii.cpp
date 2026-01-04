class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool> (n, false));

        for(int i = n - 1; i >= 0; --i) {

            for(int j = i; j < n; ++j) {

                if(i == j) {

                    pal[i][j] = true;
                }
                else {

                    pal[i][j] = s[i] == s[j];
                    
                    if(j - i + 1  >= 3) {

                        pal[i][j] = pal[i][j] && pal[i + 1][j - 1];
                    }
                }
            }
        }

        vector<int> dp(n, 0);

        dp[0] = 0;

        for(int i = 1; i < n; ++i) {

            dp[i] = pal[0][i] ? 0 : i + 1;

            for(int j = 0; j < i; ++j) {

                dp[i] = min(dp[i], dp[j] + (pal[j + 1][i] ? 1 : i - j));
            }
        }

        return dp[n - 1];
    }
};