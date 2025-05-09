class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int havz1 = 0, havz2 = 0;
        long long sum1 = 0,sum2 = 0;
        for (auto &n : nums1){
            sum1+= n;
            if (n==0) havz1++; 
        }    
        for (auto &n : nums2){
            sum2+=n;
            if (n==0) havz2++; 
        }

        if (!havz1 && !havz2) {
            if (sum1 == sum2) return sum1;
            return -1;
        }

        if (!havz1) {
            if (sum2+havz2 <= sum1) return sum1;
            return -1;
        }

        if (!havz2) {
            if (sum1+havz1 <= sum2) return sum2;
            return -1;
        }

        return max(sum1+havz1, sum2+havz2);
    }
};