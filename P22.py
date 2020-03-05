class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ret = []
        if n == 0 :
            ret.append("")
            return ret
        for i in range(n) :
            for s in self.generateParenthesis(i) :
                for l in self.generateParenthesis(n - i - 1) :
                    ret.append('(' + s + ')' + l)
        return ret