class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        
        
        vector<int> prev(m+1, 0), curr(m+1, 0);
        prev[0] = 1;  
        
        for(int i = 1; i <= n; i++){
            curr[0] = 1;  
            for(int j = 1; j <= m; j++){
                if (s[i-1] == t[j-1]) {
                    // Two choices: use current match or skip it
                    curr[j] = (long long)prev[j-1] + prev[j];
                } else {
                    // Only one choice: skip current character
                    curr[j] = prev[j];
                }
            }
            prev.swap(curr);
            }
        
        return prev[m];
    }
};