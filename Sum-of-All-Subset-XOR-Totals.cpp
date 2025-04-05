class Solution {
    int sumsub(int i,vector<int>& nums,int sum){
        if (i>=nums.size()) return sum;

        int ch1 = sumsub(i+1,nums,sum ^ nums[i]);
        int ch2 = sumsub(i+1,nums,sum);
        return ch1 + ch2;
    }

public:
    int subsetXORSum(vector<int>& nums) {
        return sumsub(0,nums,0);
    }
};