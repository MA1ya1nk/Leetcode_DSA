class Solution {
public:
    int strStr(string haystack, string needle) {
        int s1=haystack.size(),s2=needle.size();
        if(s2>s1) return -1;
        for(int i=0;i<s1;i++){
            if(haystack[i]==needle[0]){
                string temp=haystack.substr(i,s2);
                if(temp==needle) return i;
            }
        }
        return -1;
    }
};