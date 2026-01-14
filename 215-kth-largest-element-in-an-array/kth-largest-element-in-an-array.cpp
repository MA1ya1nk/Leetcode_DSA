class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    //    priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);
        
    //     for (int i = k; i < nums.size(); i++) {
    //         if (nums[i] > min_heap.top()) {
    //             min_heap.pop();
    //             min_heap.push(nums[i]);
    //         }
    //     }
        
    //     return min_heap.top();
    priority_queue<int> pq(nums.begin(),nums.end());
    while(k>1){
      pq.pop();
      k--;
    } 
    return pq.top();
    }
};