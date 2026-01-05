class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m=s.size();
       vector<vector<int>> dp(m+1,vector<int>(m+1,0));
       string rev=s;
       reverse(rev.begin(),rev.end());
       for(int i=m-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s[i]==rev[j])
               dp[i][j]=1+dp[i+1][j+1];

            else
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);   
        }
       } 

       return dp[0][0];
    }
};