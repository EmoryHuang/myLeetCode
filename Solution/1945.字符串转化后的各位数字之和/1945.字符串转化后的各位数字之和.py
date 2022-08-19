'''
Descroption: LeetCode 1945. 字符串转化后的各位数字之和
Author: EmoryHuang
Date: 2021-11-08 10:52:15
Method:
简单题，将字符串转化为数字，然后重复 k 次操作得到各位数字之和
'''


class Solution:
    def getLucky(self, s: str, k: int) -> int:
        ans = ''
        for c in s:
            ans += str(ord(c) - ord('a') + 1)
        while k:
            ans = str(sum([int(num) for num in ans]))
            k -= 1
        return int(ans)
