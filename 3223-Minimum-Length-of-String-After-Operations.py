class Solution:
    def minimumLength(self, s: str) -> int:
        freq = [0]*26

        for c in s:
            freq[ord(c)-ord('a')]+=1
        
        ans = 0

        for i in range(0,26):
            if not freq[i] : continue 
            if freq[i]&1 : ans+=1
            else : ans+=2
        
        return ans