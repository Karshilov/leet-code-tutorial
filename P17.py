class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        phone = {'2': ['a', 'b', 'c'],
                 '3': ['d', 'e', 'f'],
                 '4': ['g', 'h', 'i'],
                 '5': ['j', 'k', 'l'],
                 '6': ['m', 'n', 'o'],
                 '7': ['p', 'q', 'r', 's'],
                 '8': ['t', 'u', 'v'],
                 '9': ['w', 'x', 'y', 'z']}
        ans = []
        def dfs(depth, now):
            if (depth == len(digits)) :
                ans.append(now)
                return 
            for c in phone[digits[depth]]:
                dfs(depth + 1, now + c)
        if len(digits) != 0:
            dfs(0, "")
        return ans

