class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool> isPrime(n+1,1);
        isPrime[0]=0;
        isPrime[1]=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                count++;
                for(int j=2*i;j<=n;j=j+i){
                    isPrime[j]=0;
                }
            }
        }
      return count;
    }
};