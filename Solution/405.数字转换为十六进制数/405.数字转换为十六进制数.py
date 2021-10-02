'''
Descroption: LeetCode 405. 数字转换为十六进制数
Author: EmoryHuang
Date: 2021-10-02 16:42:47
Method:
位运算
遍历 num，每4位对应一个十六进制位
使用0xf(00...01111b)获取num的低4位
'''


class Solution:
    def toHex(self, num: int) -> str:
        if num == 0: return '0'
        hash = '0123456789abcdef'
        ans = ''
        while num and len(ans) < 8:
            # 使用0xf(00...01111b)获取num的低4位
            ans = hash[0xf & num] + ans
            num >>= 4
        return ans
