class Solution {
public:
    unordered_map<string,bool>dp;
    bool f(string s1,string s2){
        int n = s1.length();
        string s = s1 +" "+s2;
        if(s1==s2) return true;
        if(n<=1) return false;
        if(dp.count(s)) return dp[s];
        for(int i=1;i<n;i++){
            bool ans1 = f(s1.substr(0,i),s2.substr(0,i)) and f(s1.substr(i,n-i),s2.substr(i,n-i));
            bool ans2 = f(s1.substr(0,i),s2.substr(n-i,i)) and f(s1.substr(i,n-i),s2.substr(0,n-i));
            if(ans1 or ans2) return dp[s] = true;
        }
        return dp[s] = false;
    }
    bool isScramble(string s1, string s2) {
        return f(s1,s2);
    }
};