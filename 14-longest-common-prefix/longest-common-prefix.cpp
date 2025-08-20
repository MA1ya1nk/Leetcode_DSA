class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_map<int,char> m;
        string str=strs[0];
        for(int i=0;i<str.size();i++){
            m[i]=str[i];
        }
        int val=INT_MAX;
        for(int i=1;i<strs.size();i++){
            string temp=strs[i];
            if(temp=="") return "";
            int ans=0;
            for(int j=0;j<temp.size();j++){
                if(m[j] && m[j]==temp[j]){
                    ans++;
                }
                else{
                    if(ans==0) return "";
                    else break;
                }
            }
            val=min(val,ans);
        }
        return str.substr(0,val);
    }
};