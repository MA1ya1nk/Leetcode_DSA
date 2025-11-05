class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
         while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        size_t pos = temp.find_first_not_of('0');
        temp = (pos == std::string::npos) ? "0" : temp.substr(pos);
        return temp;
    }
};