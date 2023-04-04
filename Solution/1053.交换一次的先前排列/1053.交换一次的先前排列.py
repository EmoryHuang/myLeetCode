'''
Descroption: LeetCode 1053. 交换一次的先前排列
Author: EmoryHuang
Date: 2023-04-03 09:26:10
Method:
对当前序列进行逆序查找，找到第一个降序的位置 i
寻找在 A[i] 最左边且小于 A[i] 的最大的数字 A[j]
'''


class Solution:
    def prevPermOpt1(self, arr: List[int]) -> List[int]:
        n = len(arr)
        for i in range(n - 2, -1, -1):
            if arr[i] > arr[i + 1]:
                j = n - 1
                while arr[j] >= arr[i] or arr[j] == arr[j - 1]:
                    j -= 1
                arr[i], arr[j] = arr[j], arr[i]
                break
        return arr
