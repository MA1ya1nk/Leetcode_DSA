class Solution {
public:
    int minOperations(string s) {
        int len = s.size();
        string str1 = "", str2 = ""; // str1 start with 0
        for(int i=0;i<len;i++){
            if(i%2 == 0){
                str1 += '0';
                str2 += '1';
            }
            else{
                str1 += '1';
                str2 += '0';
            }
        }
        
        int fir = 0, sec = 0;
        for(int i=0;i<len;i++){
            if(str1[i]!=s[i]) fir++;
            if(str2[i]!=s[i]) sec++;
        }

        return min(fir,sec);
    }
};