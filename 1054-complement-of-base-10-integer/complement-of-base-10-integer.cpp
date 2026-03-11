class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        int temp = n;
        int i = 0;
        while(temp>0){
            n = n^(1<<i);
            i++;
            temp>>=1;
        }
        return n;
    }
};