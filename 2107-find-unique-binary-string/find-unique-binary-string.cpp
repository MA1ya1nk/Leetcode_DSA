class Solution {
public:
    string bin(int i, int n){
        bitset<32> b(i);
        string str = "";
        for(int i=n-1;i>=0;i--){
            if(b[i]==1) str += '1';
            else str += '0';
        }
        return str;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int size = 1<<n;
        vector<int> exist(size,0);
        for(int i=0;i<n;i++){
            string str = nums[i];
            int a = stoi(str, 0, 2);
            exist[a]=1;
        }
        for(int i=0;i<size;i++)
            if(exist[i]==0)
                return bin(i,n);

        return "";
    }
};