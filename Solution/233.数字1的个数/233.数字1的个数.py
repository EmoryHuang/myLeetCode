'''
Descroption: LeetCode 233. 数字 1 的个数
Author: EmoryHuang
Date: 2021-08-13 20:14:28
Method:
分别计算个、十、百、千...位上1出现的次数
'''


class Solution:
    def countDigitOne(self, n: int) -> int:
        # low为低位，cur为当前位，high为高位
        low, cur, high = 0, n % 10, n // 10
        # 从个位开始
        d = 1
        ans = 0
        while high or cur:
            if cur == 0:
                # 当前位为 0，那么只能看高位，有high种取法
                ans += high * d
            elif cur == 1:
                # 当前位为 1，在高位的基础上再加上低位
                # 因为当前位为 1 则 low 无论什么数字，都会对 1 有贡献
                ans += high * d + low + 1
            elif cur > 1:
                # 当前位大于 1，则把当前位当成high
                ans += (high + 1) * d
            low += cur * d
            d *= 10  # 下一位
            cur = high % 10
            high = high // 10
        return ans
