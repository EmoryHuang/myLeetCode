'''
Descroption: LeetCode 386. 字典序排数
Author: EmoryHuang
Date: 2022-04-18 08:45:34
Method:
dfs
对于当前数字 num
若 num * 10 <= n, 则下一个数字为 num * 10
若到达最大值, 即 num % 10 == 9 or num + 1 > n, 则退回上一位
否则下一个数字为 num + 1
'''


class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = [0] * n
        num = 1
        for i in range(n):
            ans[i] = num
            if num * 10 <= n:
                num *= 10
            else:
                # 到达最大值，则退回上一位
                while num % 10 == 9 or num + 1 > n:
                    num //= 10
                # 如果没有到达最大值，则加 1
                num += 1
        return ans