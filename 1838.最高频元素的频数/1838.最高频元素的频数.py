'''
Descroption: LeetCode 1838. 最高频元素的频数
Author: EmoryHuang
Date: 2021-07-19 14:28:15
解题思路:
方法一：排序 + 滑动窗口
判断当前滑动窗口是否满足条件
方法二：排序 + 滑动窗口 + 二分
首先，通过二分法判断当前选的频数是否可行
具体来说，通过滑动窗口进行判断，由于频数固定，因此我们可以判断，当前窗口内的元素是否满足条件
目标数字即为当前窗口右端点对应的数字，通过判断目标区间和即可判断当前窗口是否满足条件
'''


class Solution:
    # 方法一：排序 + 滑动窗口
    # def maxFrequency(self, nums: List[int], k: int) -> int:
    #     n = len(nums)
    #     nums.sort()
    #     l = r = diff = 0
    #     ans = 1
    #     for r in range(1, n):  # 遍历滑动窗口右端点
    #         diff += (r - l) * (nums[r] - nums[r - 1])
    #         if diff > k:
    #             diff -= nums[r] - nums[l]
    #             l += 1
    #         ans = max(ans, r - l + 1)
    #     return ans

    # 方法二：排序 + 滑动窗口 + 二分
    def maxFrequency(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        pre = [0] * (n + 1)
        for i in range(1, n + 1):
            pre[i] = pre[i - 1] + nums[i - 1]

        # 判断当前频数是否可行
        def check(fre: int) -> bool:
            # 遍历滑动窗口左端点
            for i in range(n + 1 - fre):
                j = i + fre - 1  # 滑动窗口右端点
                diff = fre * nums[j] - (pre[j + 1] - pre[i])
                if diff <= k:
                    return True
            return False

        l, r = 0, n
        while l < r:
            mid = l + r + 1 >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
