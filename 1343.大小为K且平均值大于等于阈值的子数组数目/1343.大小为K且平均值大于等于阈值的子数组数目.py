'''
Descroption: LeetCode 1343. 大小为 K 且平均值大于等于阈值的子数组数目
Author: EmoryHuang
Date: 2021-07-25 14:23:35
Method:
简单题，固定长度的滑动窗口
'''


class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        s = sum(arr[:k])
        ans = 0 if s / k < threshold else 1
        for i in range(k, len(arr)):
            s += arr[i]
            s -= arr[i - k]
            if s / k >= threshold:
                ans += 1
        return ans
