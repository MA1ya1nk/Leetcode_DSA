class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minSize = INT_MAX;
        string ans = "";
        for(int i=0;i<strs.size();i++){
            int size = strs[i].size();
            minSize = min(minSize,size);
        }

        for(int i=0;i<minSize;i++){
            string tem = strs[0];
            char ch = tem[i];
            for(int j=0;j<strs.size();j++){
                string temp = strs[j];
                if(temp[i]!=ch) return ans;
            }
            ans += ch;
        }

        return ans;
    }
};