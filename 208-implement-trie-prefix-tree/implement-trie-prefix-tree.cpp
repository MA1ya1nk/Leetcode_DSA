class trieNode{
   public:
   char val;
   trieNode* children[26];
   bool isComplete;

   trieNode(char ch){
    val=ch;
    for(int i=0;i<26;i++){
        children[i]=NULL;
    }
    isComplete=false;
   }
};
class Trie {
public:
    trieNode* root;
    Trie() {
        root=new trieNode('\0');
    }
    
    void insertUtil(trieNode* root,string word){
        if(word.length()==0){
            root->isComplete=true;
            return ;
        }
        int ind=word[0]-'a';
        trieNode* child;
        if(root->children[ind]!=NULL){
            child=root->children[ind];
        }
        else{
            child=new trieNode(word[0]);
            root->children[ind]=child;
        }
        insertUtil(child,word.substr(1));
    }
    void insert(string word) {
        insertUtil(root,word);
    }
    
    bool searchUtil(trieNode* root,string word){
        if(word.length()==0){
            return root->isComplete;
        }
        int ind=word[0]-'a';
        trieNode* child;
        if(root->children[ind]!=NULL){
            child=root->children[ind];
        }
        else return false;
        
        return searchUtil(child,word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root,word);
    }
    
    bool startWithUtil(trieNode* root,string prefix){
         if(prefix.length()==0){
            return true;
        }
        int ind=prefix[0]-'a';
        trieNode* child;
        if(root->children[ind]!=NULL){
            child=root->children[ind];
        }
        else return false;
        
        return startWithUtil(child,prefix.substr(1));
    }
    bool startsWith(string prefix) {
        return startWithUtil(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */