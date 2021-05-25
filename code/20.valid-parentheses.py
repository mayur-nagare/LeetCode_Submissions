class Solution:
    def isValid(self, s: str) -> bool:
        res, stack = [], {"(": ")", "[": "]", "{": "}"}
        for i in s:
            if i in stack :
                res.append(i)
            elif len(res) == 0 or stack[res.pop()] != i:
                return False
        return len(res) == 0
                
        