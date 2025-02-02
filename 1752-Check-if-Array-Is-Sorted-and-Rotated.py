class Solution:
    def check(self, nums: List[int]) -> bool:
        for i in range (0,len(nums)):
            p = i+1
            if p == len(nums) : p = 0
            good = True
            while(p != i):
                if nums[p] < nums[p-1]:
                    good = False
                    break
                p+=1
                if p == len(nums) : p = 0
            if good : return good

        return False
