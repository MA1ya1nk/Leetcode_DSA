class Solution {
public:
    bool checkOnesSegment(string s) {
        bool one = true;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0') one = false;
            if(s[i]=='1' && one==false) return false;
        }

        return true;
    }
};