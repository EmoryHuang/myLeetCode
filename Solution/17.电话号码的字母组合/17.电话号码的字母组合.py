'''
Descroption: LeetCode 17. 电话号码的字母组合
Author: EmoryHuang
Date: 2023-04-11 09:43:55
Method:
回溯
每次取电话号码的一位数字，从哈希表中获得该数字对应的所有可能的字母，
并将其中的一个字母插入到已有的字母排列后面，然后继续处理电话号码的后一位数字，
直到处理完电话号码中的所有数字，即得到一个完整的字母排列
'''


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def backtrace(cur, digits, index):
            if index == len(digits):
                ans.append(''.join(cur))
                return
            num = int(digits[index])
            for c in m[num]:
                cur.append(c)
                backtrace(cur, digits, index + 1)
                cur.pop()

        if not digits:
            return []
        ans = []
        m = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        backtrace([], digits, 0)
        return ans
