class Solution {
    vector <bool> isprime ;
    void seive(){
        isprime[0] = isprime[1] = 0;
        for (int i=2 ; i*i<1000001 ; i++){
            if (isprime[i]){
                int x = i*i;
                while(x<1000001){
                    isprime[x]=0;
                    x+=i;
                }
            }
        } 
    }

public:
    vector<int> closestPrimes(int left, int right) {
        isprime.assign(1000001,true);
        seive();
        vector <int> ans(2,-1);
        int lst = -1,mn = right-left+1;
        for (int i=left ; i<=right ; i++){
            if (isprime[i]){
                if (lst!=-1){
                    if (i-lst < mn) {
                        mn = i-lst;
                        ans[0] = lst;
                        ans[1] = i;
                    }
                }
                lst = i; 
            }
        }

        return ans;
    }
};