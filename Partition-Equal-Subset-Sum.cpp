class Solution {
    int total;
    vector <vector<int>> dp;

    int rec(int i,vector<int>& nums,int sum1){
        if (i >= nums.size()) return sum1 == total-sum1;
        int n = nums[i];
        int &ret = dp[i][sum1];
        if (~ret) return ret;
        return ret = rec(i+1,nums,sum1+n) | rec(i+1, nums,sum1);
    }

public:
    bool canPartition(vector<int>& nums) {
        total = accumulate(nums.begin(),nums.end(),0);
        dp = vector <vector <int> > (205,vector <int>(20005,-1));
        return rec(0,nums,0);
    }
};