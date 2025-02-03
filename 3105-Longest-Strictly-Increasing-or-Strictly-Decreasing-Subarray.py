class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        ans = 1
        cnti = 1
        cntd = 1
        for i in range(1,len(nums)):
            if nums[i] < nums[i-1]:
                cntd += 1
                cnti = 1
            elif nums[i] > nums[i-1]:
                cnti += 1
                cntd = 1
            else:
                cnti = 1
                cntd = 1
            ans = max(ans,max(cnti,cntd))
        
        return ans