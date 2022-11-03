'''
Descroption: LeetCode 927. 三等分
Author: EmoryHuang
Date: 2022-10-06 11:28:30
Method:
模拟
首先判断和必须是 3 的倍数，并得到每段 1 的数量
遍历数组找到每段第一个 1 出现的位置
接着往后同时遍历每一部分，判断三部分对应的值是否相等，直到末尾
遍历结束时，如果到达末尾则说明可三等分
'''


class Solution:
    def threeEqualParts(self, arr: List[int]) -> List[int]:
        s = sum(arr)
        # 必须是 3 的倍数
        if s % 3:
            return [-1, -1]
        # 全 0
        if s == 0:
            return [0, 2]

        p = s // 3  # 每段 1 的数量
        # 找到每段第一个 1 出现的位置
        first = second = third = cur = 0
        for i, num in enumerate(arr):
            if num == 1:
                if cur == 0:
                    first = i
                elif cur == p:
                    second = i
                elif cur == 2 * p:
                    third = i
                cur += 1

        n = len(arr)
        # 往后同时遍历每一部分，判断三部分对应的值是否相等，直到末尾
        while third < n and arr[first] == arr[second] == arr[third]:
            first, second, third = first + 1, second + 1, third + 1
        return [first - 1, second] if third == n else [-1, -1]
