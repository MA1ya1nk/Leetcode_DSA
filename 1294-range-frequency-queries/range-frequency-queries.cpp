class ST{
    vector<unordered_map<int,int>> st;
    int n;
    void build(int node, int l , int r, vector<int>& nums){
        if(l == r){
            st[node][nums[l]]++;
            return;
        }
        int mid = (r+l)/2;
        build(2*node+1,l,mid,nums);
        build(2*node+2,mid+1,r,nums);
        for(auto [k,v] : st[2*node+1]){
            st[node][k] += v;
        }
        for(auto [k,v] : st[2*node+2]){
            st[node][k] += v;
        }
    }
public:
    ST(vector<int> nums){
        n = nums.size();
        st.resize(4*n);
        build(0,0,n-1,nums);
    }
    int query(int node, int l , int r, int ql ,int qr, int val){
        if(l > qr or r < ql) {
            return 0;
        }
        if(ql <= l and r <= qr){
            return st[node].count(val) ? st[node][val] : 0;
        }
        int mid = (r+l)/2;
        return query(2*node+1,l,mid,ql,qr,val) + query(2*node+2,mid+1,r,ql,qr,val);
    }
};
class RangeFreqQuery {
public:
    ST* st;
    int n;
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        st = new ST(arr);
    }
    
    int query(int left, int right, int value) {
        return st->query(0,0,n-1,left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */