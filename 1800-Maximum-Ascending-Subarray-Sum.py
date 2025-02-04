class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        ans = 0
        lst = 0
        sum = 0
        for i in range(len(nums)):
            if (nums[i]>lst):
                sum += nums[i]
            else:
                sum = nums[i]
            ans = max (ans,sum) 
            lst = nums[i]
        
        return ans