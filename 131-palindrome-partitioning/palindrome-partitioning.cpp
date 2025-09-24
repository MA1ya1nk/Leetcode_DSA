class Solution {
public:
    bool palindrome(vector<string> temp){
        for(int i=0;i<temp.size();i++){
            string str=temp[i];
            int s=0,e=str.size()-1;
            while(s<e){
                if(str[s]!=str[e]) return false;
                s++;
                e--;
            }
        }
        return true;
    }
    void solve(int i,string s,vector<string>& temp,vector<vector<string>>& ans){
        if(i>=s.size()){
            if(palindrome(temp)) ans.push_back(temp);
            return ;
        }

        for(int j=i;j<s.size();j++){
            string tem=s.substr(i,j-i+1);
            temp.push_back(tem);
            solve(j+1,s,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        solve(0,s,temp,ans);
        return ans;
    }
};