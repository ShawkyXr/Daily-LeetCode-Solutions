class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int max_sum = nums[0],curr_sum_max = nums[0],curr_sum_min = nums[0],min_sum = nums[0], ans = abs(nums[0]);

        for (int i=1 ; i<nums.size() ;i++){
            curr_sum_max = max(curr_sum_max + nums[i],nums[i]);
            max_sum = max(max_sum,curr_sum_max);

            curr_sum_min = min(curr_sum_min + nums[i],nums[i]);
            min_sum = min(min_sum,curr_sum_min);

            ans = max({ans,abs(max_sum),abs(min_sum)});
        }

        return ans;
    }
};