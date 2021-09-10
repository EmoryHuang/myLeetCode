'''
Descroption: LeetCode 1598. 文件夹操作日志搜集器
Author: EmoryHuang
Date: 2021-06-20 12:41:00
解题思路:
若 log == './' 不进行操作
若 log == '../ 则 cnt - 1
否则 cnt + 1
'''


class Solution:
    def minOperations(self, logs: List[str]) -> int:
        cnt = 0
        for log in logs:
            if log == './':
                pass
            elif log == '../':
                cnt = max(0, cnt - 1)
            else:
                cnt += 1
        return cnt
