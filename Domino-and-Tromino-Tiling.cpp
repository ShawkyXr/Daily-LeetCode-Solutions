class Solution {
    vector <int> dp;
    int rec(int n){
        if (n==1){
            return 1;
        }
        if (n==2){
            return 2;
        }
        if (n==3){
            return 5;
        }
        int &ret = dp[n];
        if (~ret) return ret;
        return ret = ((rec(n-1)*2)%1000000007  + rec(n-3)%1000000007)%1000000007;
    }
public:
    int numTilings(int n) {
        dp.assign(n+1,-1);
        return rec(n);
    }
};