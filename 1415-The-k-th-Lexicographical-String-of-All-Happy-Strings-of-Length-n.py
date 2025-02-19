class Solution:
    def __init__(self):
        self.sets = []
    def getHappyString(self, n: int, k: int) -> str:

        def rec(n,s):
            if len(s)==n:
                self.sets.append(s)
                return
            

            if s[-1] == 'a':
                rec(n,s+'b')
                rec(n,s+'c')
            elif s[-1] == 'b':
                rec(n,s+'a')
                rec(n,s+'c')
            else:
                rec(n,s+'a')
                rec(n,s+'b')
            
        rec(n,"a")
        rec(n,"b")
        rec(n,"c")

        self.sets.sort()

        return self.sets[k-1] if k <= len(self.sets) else "" 

        