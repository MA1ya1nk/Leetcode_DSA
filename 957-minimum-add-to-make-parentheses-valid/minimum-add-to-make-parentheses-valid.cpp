class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        st.push(' ');
        for(int i=0;i<s.size();i++){
           char ch=s[i];
           if(ch==')' && st.top()=='(') st.pop();
           else st.push(ch);
        }

        return (st.size()-1);
    }
};