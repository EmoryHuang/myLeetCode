'''
Descroption: LeetCode 1346. 检查整数及其两倍数是否存在
Author: EmoryHuang
Date: 2021-07-25 14:37:15
Method:
简单题，使用哈希表存储元素
数字0需要特殊考虑
'''


class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        counter = collections.Counter(arr)
        for num in arr:
            if num and counter[num * 2] >= 1:
                return True
            # 数字0需要特殊考虑
            if not num and counter[num * 2] >= 2:
                return True
        return False