'''
Descroption: LeetCode 611. 有效三角形的个数
Author: EmoryHuang
Date: 2021-08-04 14:55:15
Method:
从大到小遍历最长边，然后设置双指针寻找合适的`j`，`k`，`[j, k - 1]`都符合条件
'''


class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        cnt = 0
        for a in range(len(nums) - 1, 1, -1):
            b, c = 0, a - 1
            while b < c:
                # 如果能组成三角形
                if nums[a] < nums[b] + nums[c]:
                    cnt += c - b
                    c -= 1
                else:
                    b += 1
        return cnt