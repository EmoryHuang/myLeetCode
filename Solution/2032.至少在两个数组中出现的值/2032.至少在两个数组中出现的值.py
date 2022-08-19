'''
Descroption: LeetCode 2032. 至少在两个数组中出现的值
Author: EmoryHuang
Date: 2021-10-16 19:19:08
Method:
哈希表
使用哈希表记录3个数组中数字出现的数量，将出现次数大于 2 的加入 ans
'''


class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int],
                      nums3: List[int]) -> List[int]:
        cnt = Counter(set(nums1)) + Counter(set(nums2)) + Counter(set(nums3))
        ans = []
        for key, val in cnt.items():
            if val >= 2:
                ans.append(key)
        return ans
