class Node{
    public:
    int ke,val;
    Node* prev;
    Node* next;
    Node(int k,int v){
        ke=k;
        val=v;
        prev=next=NULL;
    }
};
class LRUCache {
public:
int size=-1;
    unordered_map<int,Node*> m;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    LRUCache(int capacity) {
        size=capacity;
        m.clear();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            deleteNode(m[key]);
            insertAtHead(m[key]);
            return m[key]->val;
        }
        return -1;
    }
    
    void insertAtHead(Node* &temp){
        Node* forw=head->next;
        head->next=temp;
        temp->prev=head;
        temp->next=forw;
        forw->prev=temp;
    }
    void deleteNode(Node* &temp){
        Node* forw=temp->next;
        Node* back=temp->prev;
        back->next=forw;
        forw->prev=back;
    }
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            m[key]->val=value;
            deleteNode(m[key]);
            insertAtHead(m[key]);
        }
        else{
        if(size==m.size()){
            Node* last=tail->prev;
            m.erase(last->ke);
            deleteNode(last);
            Node* temp=new Node(key,value);
            m[key]=temp;           
            insertAtHead(temp);
        }
        else{
            Node* temp=new Node(key,value);
            m[key]=temp;
            insertAtHead(temp);
        }
        } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */