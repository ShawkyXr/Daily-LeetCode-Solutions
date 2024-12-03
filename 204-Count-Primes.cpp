class Solution {
    
public:
    int countPrimes(int n) {
        int ans =0;
        vector <bool> sieve(n+1,1);
        sieve[0]=0;
        sieve[1]=0;
        for (int i=2 ; i<n ;i++){
            if (sieve[i]){
                ans++;
                for (int j = i*2 ; j<n ;j+=i){
                    sieve[j]=0;
                }
            }
        }
    return ans;
    }
};