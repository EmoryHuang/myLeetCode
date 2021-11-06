'''
Descroption: LeetCode 1980. 找出不同的二进制字符串
Author: EmoryHuang
Date: 2021-11-06 16:13:30
Method:
回溯
dfs 遍历字符串，若找到了一个不同的二进制字符串，则跳出循环
'''


class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        def dfs(cur: str):
            if not self.flag:
                if len(cur) == len(nums):
                    if cur not in nums:
                        self.ans = cur
                        self.flag = True
                    return
                for c in ['0', '1']:
                    dfs(cur + c)

        self.ans = ''
        self.flag = False
        dfs('')
        return self.ans
