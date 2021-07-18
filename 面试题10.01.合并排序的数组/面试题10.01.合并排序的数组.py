'''
Descroption: 面试题 10.01. 合并排序的数组
Author: EmoryHuang
Date: 2021-07-18 15:02:29
解题思路:
一个简单的方法就是将数组 B 放进数组 A 的尾部，然后直接排序
再进一步的话可以使用双指针，从左向右比较数组中元素的大小，将元素放到新的数组中
当然，由于 A 后面有足够的空间，因此可以使用逆向双指针
'''


class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i, j = m - 1, n - 1
        tail = m + n - 1
        while i >= 0 or j >= 0:
            if i == -1:
                A[tail] = B[j]
                j -= 1
            elif j == -1:
                A[tail] = A[i]
                i -= 1
            elif A[i] > B[j]:
                A[tail] = A[i]
                i -= 1
            else:
                A[tail] = B[j]
                j -= 1
            tail -= 1
