'''
Descroption: LeetCode 902. 最大为 N 的数字组合
Author: EmoryHuang
Date: 2022-10-18 09:39:40
Method:
排列组合
当数字位数小于 n 时，生成整数必定小于 n，每位共有 len(digits) 种可能
当数字位数等于 n 时，从左到右遍历每位，
最高位依据 digits 中的数字，剩下的低位每位共有 len(digits) 种可能
另外再考虑是否数字相等
'''


class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        s = str(n)
        nd, ns = len(digits), len(s)
        # 当数字位数小于 n 时，生成整数必定小于 n
        # 每位共有 len(digits) 种可能
        ans = sum(nd**i for i in range(1, ns))
        # 当数字位数等于 n 时，从左到右遍历每位
        for i, c in enumerate(s):
            # 当 digits 中存在小于最高位的数字时
            # 最高位依据 digits 中的数字，剩下的低位每位共有 len(digits) 种可能
            ans += nd**(ns - i - 1) * sum([d < c for d in digits])
            if c not in digits:
                return ans
        return ans + 1