class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        n = len(words)
        pre = [0]*n

        for i in range(n):
            fi = words[i][0]
            lst = words[i][len(words[i])-1]
            if (fi == 'a' or fi == 'e' or fi == 'i' or fi == 'o' or fi == 'u') and (lst == 'a' or lst == 'e' or lst == 'i' or lst == 'o' or lst == 'u'):
                pre[i] = 1
            
            if i != 0 : pre[i]+=pre[i-1]
        
        ans = []

        for q in queries:
            l = q[0]
            r = q[1]
            if l == 0:
                ans.append(pre[r])
            else:
                ans.append(pre[r]-pre[l-1])

        return ans
        