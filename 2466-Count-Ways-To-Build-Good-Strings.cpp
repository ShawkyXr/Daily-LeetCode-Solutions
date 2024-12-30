class Solution {
    vector <int> dp;
    int rec(int s,int low, int high, int zero, int one){
        if (s>high) return 0;
        int &ret = dp[s];
        if (~ret) return ret;
        int ch1 = rec(s+zero,low,high,zero,one) + (s+zero >= low && s+zero<=high ? 1 : 0);
        int ch2 = rec(s+one,low,high,zero,one) + (s+one >= low && s+one<=high ? 1 : 0);
        return ret = ((ch1%1000000007) + (ch2%1000000007))%1000000007;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.assign(100005,-1);
        return rec(0,low,high,zero,one);
    }
};