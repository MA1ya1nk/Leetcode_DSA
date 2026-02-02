class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        int a = n,i = 0;
        while(a){
            n = n^(1<<i);
            i++;
            a /= 2;
        }
        return n;
    }
};