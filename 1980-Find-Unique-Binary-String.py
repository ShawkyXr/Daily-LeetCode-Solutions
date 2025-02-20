class Solution:
    # def __init__(self):
    #     sets = []
    
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        sets = []
        def gen(i,n,s):
            if (i==n):
                sets.append(s)
                return

            gen(i+1,n,s+'0')
            gen(i+1,n,s+'1')
        
        gen(0,len(nums[0]),"")

        for s in sets:
            if not s in nums:
                return s
        return "" 

