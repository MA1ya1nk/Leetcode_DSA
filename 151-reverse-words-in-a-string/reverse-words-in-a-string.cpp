class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<char> st;
        st.push(' ');
        for(char ch:s){
            if(ch==' '){
                if(st.size() && st.top()!=' '){
                    st.push(ch);
                }
            }
            else st.push(ch);
        }
        if(st.top()==' ') st.pop();
        string temp;
        while(!st.empty()){
            if(st.top()==' '){
                reverse(temp.begin(),temp.end());
                temp+=" ";
                ans+=temp;
                temp="";
            }
            else temp+=st.top();
            st.pop();

        }
        ans.pop_back();        
        return ans;
    }
};