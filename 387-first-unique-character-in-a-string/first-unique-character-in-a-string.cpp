class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> freq;
        queue<int> q;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
            q.push(i);
        }
        while(!q.empty()){
            int first = q.front();
            q.pop();
            if(freq[s[first]]==1) return first;
        }
        return -1;
    }
};