class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        ans = 0
        for s in words :
            if s.startswith(pref) : ans+=1
        return ans