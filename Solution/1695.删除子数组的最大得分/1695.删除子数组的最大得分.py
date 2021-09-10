'''
Descroption: LeetCode 1695. 删除子数组的最大得分
Author: EmoryHuang
Date: 2021-08-10 14:52:18
Method:
滑动窗口
遍历数组，若当前元素未加入，则加入窗口，
否则若遍历到了重复元素，则移动左窗口，删除重复元素之前的所有元素
'''


class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, 0
        ans, sum, hash = 0, 0, []
        while r < n:
            # 若当前元素未加入
            if nums[r] not in hash:
                hash.append(nums[r])
                sum += nums[r]
                ans = max(ans, sum)
            else:
                # 删除重复元素之前的所有元素
                while nums[l] != nums[r]:
                    sum -= nums[l]
                    hash.remove(nums[l])
                    l += 1
                l += 1
            r += 1
        return ans
