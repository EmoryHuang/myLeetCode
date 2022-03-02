'''
Descroption: LeetCode 564. 寻找最近的回文数
Author: EmoryHuang
Date: 2022-03-02 09:06:01
Method:
构造回文数可以用原数的较高位的数字替换其对应的较低位
但这样同样也有一些特殊情况，比如：
99 最近的是 101 而不是根据贪心生成的 88 或 1001

计算以下每一种可能，找到最近的回文数
1. 用原数的前半部分替换后半部分
2. 用原数的前半部分加一后的结果替换后半部分
3. 用原数的前半部分减一后的结果替换后半部分
4. 直接构造 999...999 和 100...001 的回文数
'''


class Solution:
    def nearestPalindromic(self, n: str) -> str:
        m = len(n)
        near = [10**(m - 1) - 1, 10**m + 1]
        # 原数的前半部分
        pre = int(n[:(m + 1) // 2])

        # 1. 用原数的前半部分替换后半部分
        # 2. 用原数的前半部分加一后的结果替换后半部分
        # 3. 用原数的前半部分减一后的结果替换后半部分
        for i in range(pre - 1, pre + 2):
            # 区分奇数偶数长度
            j = i if m % 2 == 0 else i // 10
            while j:
                i = i * 10 + j % 10
                j //= 10
            near.append(i)

        # 寻找最近的回文数
        ans, real = -1, int(n)
        for p in near:
            if p != real:  # 不能等于自身
                if ans == -1 or abs(p - real) < abs(ans - real) or (
                        abs(p - real) == abs(ans - real) and p < ans):
                    ans = p
        return str(ans)