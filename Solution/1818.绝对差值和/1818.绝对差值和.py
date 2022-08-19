'''
Descroption: LeetCode 1818. 绝对差值和
Author: EmoryHuang
Date: 2021-07-14 20:11:40
解题思路:
二分法
遍历每个序列，找到当前对应差值的绝对值 diff
二分法寻找 nums1 中最接近 nums2[i] 的数字，找到后得到新的差值
（因为是绝对值，所以计算差值要考虑两边）
记录可以减小的最大的差值
'''


class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        sort = sorted(nums1)
        sum = max_diff = 0
        # 遍历每个序列
        for i in range(n):
            a, b = nums1[i], nums2[i]
            if a == b:
                continue
            diff = abs(a - b)  # 当前对应差值的绝对值
            sum += diff  # 绝对差值和
            # 二分法寻找 nums1 中最接近 b 的数字
            l, r = 0, n - 1
            while l < r:
                mid = (l + r + 1) // 2
                if sort[mid] <= b:
                    l = mid
                else:
                    r = mid - 1
            # 得到新的差值
            new_diff = abs(sort[l] - b)
            if l + 1 < n:
                # 因为是绝对值，所以要考虑两边
                new_diff = min(new_diff, abs(sort[l + 1] - b))
            if new_diff < diff:
                # 记录可以减小的最大的差值
                max_diff = max(max_diff, diff - new_diff)
        return (sum - max_diff) % 1000000007
