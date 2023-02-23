'''
Descroption: LeetCode 1687. 从仓库到码头运输箱子
Author: EmoryHuang
Date: 2022-12-07 15:56:55
Method:
贪心
'''


class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        if 6 * len(nums1) < len(nums2) or 6 * len(nums2) < len(nums1):
            return -1  # 优化
        d = sum(nums2) - sum(nums1)  # 数组元素和的差，我们要让这个差变为 0
        if d < 0:
            d = -d
            nums1, nums2 = nums2, nums1  # 统一让 nums1 的数变大，nums2 的数变小
        ans = 0
        # 统计每个数的最大变化量（nums1 的变成 6，nums2 的变成 1）
        cnt = Counter(6 - x for x in nums1) + Counter(x - 1 for x in nums2)
        for i in range(5, 0, -1):  # 从大到小枚举最大变化量 5 4 3 2 1
            if i * cnt[i] >= d:  # 可以让 d 变为 0
                return ans + (d + i - 1) // i
            ans += cnt[i]  # 需要所有最大变化量为 i 的数
            d -= i * cnt[i]
