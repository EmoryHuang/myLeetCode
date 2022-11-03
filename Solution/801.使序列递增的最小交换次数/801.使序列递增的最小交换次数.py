'''
Descroption: LeetCode 801. 使序列递增的最小交换次数
Author: EmoryHuang
Date: 2022-10-10 09:41:50
Method:
动态规划
由于只能交换同位置元素，则至少满足下列条件的一种：
nums1[i] > nums1[i - 1] and nums2[i] > nums2[i - 1]
nums1[i] > nums2[i - 1] and nums2[i] > nums1[i - 1]
dp[i][0] 表示到位置i序列递增的最小交换次数，不交换nums1[i]与nums2[i]
dp[i][1] 表示到位置i序列递增的最小交换次数，交换nums1[i]与nums2[i]
空间可优化
'''


class Solution:

    def minSwap(self, nums1: List[int], nums2: List[int]) -> int:
        # dp[i][0] 表示到位置i序列递增的最小交换次数，不交换nums1[i]与nums2[i]
        # dp[i][1] 表示到位置i序列递增的最小交换次数，交换nums1[i]与nums2[i]
        # 空间可优化
        # a, b分别表示不交换与交换的次数
        a, b = 0, 1
        for i in range(1, len(nums1)):
            at = bt = float('inf')
            if nums1[i] > nums1[i - 1] and nums2[i] > nums2[i - 1]:
                at = a  # 不交换
                bt = b + 1  # 交换
            if nums1[i] > nums2[i - 1] and nums2[i] > nums1[i - 1]:
                # 同时满足则取较小值
                at = min(at, b)
                bt = min(bt, a + 1)
            a, b = at, bt
        return min(a, b)
