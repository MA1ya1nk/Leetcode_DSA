class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        if(s==goal) return true;

        int len1=s.length(), len2= goal.length();
        for(int i=0;i<s.length();i++){
            if(s[i]==goal[0]){
                string str=s.substr(i);
                string str2=goal.substr(0,str.length());
                int len=str2.length();
                if(str == str2){
                    string str3 = s.substr(0,i);
                    string str4= goal.substr(len);
                    if(str3 == str4) return true;
                }
            }
        }
        return false;
    }
};