'''
Descroption: LeetCode 1640. 能否连接形成数组
Author: EmoryHuang
Date: 2022-09-22 09:28:30
Method:
使用哈希表记录每个数组的首元素
之后遍历arr,寻找数组首元素并判断数组顺序是否一致
'''


class Solution:

    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        hash = {p[0]: p for p in pieces}
        idx = 0
        while idx < len(arr):
            if arr[idx] not in hash:
                return False
            p = hash[arr[idx]]
            if arr[idx:idx + len(p)] != p:
                return False
            idx += len(p)
        return True