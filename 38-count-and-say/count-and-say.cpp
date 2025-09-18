class Solution {
public:
    void ans(int i,int n,string & str){
        if(i==n+1) return ; 
        
        string temp=str;
        str.clear();
        int count=1;
        for(int x=0;x<temp.size()-1;x++){
           if(temp[x]!=temp[x+1]){
              str+=to_string(count);
              str+=temp[x];
              count=1;
           }
           else count++;
        }
        str+=to_string(count);
        str+=temp[temp.size()-1];
        ans(i+1,n,str);
    }
    string countAndSay(int n) {
    //    if(n==1) return "1";
        string str="1";
        ans(2,n,str);
        return str;
    }
};