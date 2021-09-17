'''
Descroption: LeetCode 1423. 可获得的最大点数
Author: EmoryHuang
Date: 2021-09-17 19:22:08
Method:
滑动窗口
滑动窗口大小为 n - k
保证滑动窗口内元素最小，也就是剩下的元素最小
'''


class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        # 滑动窗口大小为 n - k
        r = sum(cardPoints[:(n - k)])
        ans = r
        for i in range(n - k, n):
            r += cardPoints[i] - cardPoints[i - n + k]
            # 保证滑动窗口内元素最小，也就是剩下的元素最小
            ans = min(ans, r)
        return sum(cardPoints) - ans
