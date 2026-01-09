class trie{
   public:
   trie* child[2];

   trie(){
    child[0]=child[1]=NULL;
   }
};
class Solution {
public:
    trie* temp;
    void insert(int n){
        trie* t=temp;
        bitset<32> bs(n);

        for(int i=31;i>=0;i--){
            if(!t->child[bs[i]])
                t->child[bs[i]]=new trie();
                
                t=t->child[bs[i]];
        }
    }

    int maxXOR(int n){
        trie* t= temp;
        bitset<32> bs(n);
        int ans=0;

        for(int i=31;i>=0;i--){
            if(t->child[!bs[i]]){
                ans+=(1<<i);
                t=t->child[!bs[i]];
            }
            else t=t->child[bs[i]];
        }
        return ans;
    }
    

    int findMaximumXOR(vector<int>& nums) {
        // adding elements into trie
        temp=new trie();
        for(auto i:nums) insert(i);
        int ans=0;
        for(auto i:nums) ans=max(ans,maxXOR(i));
        return ans;
    }
};