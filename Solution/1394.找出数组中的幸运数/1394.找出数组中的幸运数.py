'''
Descroption: LeetCode 1394. 找出数组中的幸运数
Author: EmoryHuang
Date: 2021-08-20 19:38:35
Method:
哈希表记录每个字符出现的次数
若出现频次和它的数值大小，则记录并找到最大值
'''


class Solution:
    def findLucky(self, arr: List[int]) -> int:
        cnt = Counter(arr)
        ans = -1
        for key, val in cnt.items():
            if key == val:
                ans = max(ans, key)
        return ans
