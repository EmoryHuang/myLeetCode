'''
Descroption: LeetCode 658. 找到 K 个最接近的元素
Author: EmoryHuang
Date: 2022-08-25 19:40:14
Method:
按最接近x的元素进行排序
'''


class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        arr.sort(key=lambda v: abs(x - v))
        return sorted(arr[:k])