class Solution {
public:
     int ans=0;
void merge(vector<int>& nums,int i,int e){
    int mid=(i+e)>>1;
    vector<int> fir,sec;
    for(int a=i;a<=mid;a++) fir.push_back(nums[a]);
    for(int a=mid+1;a<=e;a++) sec.push_back(nums[a]);
    int ind=i,x=0,y=0;
    while(x<fir.size() && y<sec.size()){
        if(fir[x] > 2LL * sec[y]){
             ans+=(fir.size()-x);
             y++;
        }
        else x++;     
    }
    x=0;y=0;
    while(x<fir.size() && y<sec.size()){
        if(fir[x]<sec[y]) nums[ind++]=fir[x++];
        else nums[ind++]=sec[y++];
    }
    while(x<fir.size()) nums[ind++]=fir[x++];
    while(y<sec.size()) nums[ind++]=sec[y++];
  }
void mergeSort(vector<int>& nums,int i,int e){
    if(i>=e) return ;
    int mid=(i+e)>>1;
    mergeSort(nums,i,mid);
    mergeSort(nums,mid+1,e);
    merge(nums,i,e);
}
    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return ans;
    }
};