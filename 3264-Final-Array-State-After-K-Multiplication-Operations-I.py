class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        while(k):
            nums[nums.index(min(nums))] *= multiplier
            k-=1
        return nums