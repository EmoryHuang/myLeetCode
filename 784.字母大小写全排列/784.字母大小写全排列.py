'''
Descroption: LeetCode 784. 字母大小写全排列
Author: EmoryHuang
Date: 2021-07-26 14:14:00
Method:
dfs回溯
有大写小写两种可能
'''


class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        ans = []

        def dfs(path: str, pos: int) -> None:
            if pos == len(s):
                ans.append(path)
                return
            if s[pos].isdigit():
                dfs(path + s[pos], pos + 1)
            else:
                dfs(path + s[pos].lower(), pos + 1)
                dfs(path + s[pos].upper(), pos + 1)

        dfs('', 0)
        return ans
