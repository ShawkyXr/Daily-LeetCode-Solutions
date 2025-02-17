class Solution:
    def __init__(self):
        self.sets = set()

    def backtrack(self, i,freq,arr):

        if (len(arr)) > 0 : 
            self.sets.add(arr)
        
        for i in range(26):
            if (freq[i]>0):
                # self.backtrack(i+1,freq,arr)
                freq[i]-=1
                self.backtrack(i+1,freq,arr + chr(ord('a') + i))
                freq[i]+=1

    def numTilePossibilities(self, tiles: str) -> int:
        freq = [0]*26
        for c in tiles:
            freq[ord(c)-ord('A')]+=1
        self.backtrack(0,freq,"")
        return len(self.sets)