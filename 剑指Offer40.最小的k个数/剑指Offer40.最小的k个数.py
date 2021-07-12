'''
Descroption: 剑指 Offer 40. 最小的k个数
Author: EmoryHuang
Date: 2021-07-12 20:59:44
解题思路:
方法一：排序
直接排序选取前 k 个元素
方法二：堆
建立堆，使堆中元素小于 k
方法三：二分思想
小于等于分界值 pivot 的元素的都会被放到数组的左边，大于的都会被放到数组的右边
'''


class Solution:
    # 方法一：排序
    # def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
    #     return arr.sort()[:k]

    # 方法二：堆
    # def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
    #     heapq.heapify(arr)
    #     return nsmallest(k, arr)

    # 方法三：快排思想
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:

        def partition(l: int, r: int) -> int:
            i = random.randint(l, r)
            arr[l], arr[i] = arr[i], arr[l]
            pivot = arr[l]
            left, right = l, r
            while left < right:
                while left < right and arr[right] >= pivot:
                    right -= 1
                while left < right and arr[left] <= pivot:
                    left += 1
                if left < right:
                    arr[left], arr[right] = arr[right], arr[left]
            arr[left], arr[l] = arr[l], arr[left]
            return left

        def selected(l: int, r: int) -> None:
            if l >= r:
                return
            pos = partition(l, r)
            if k == pos:
                return
            elif k > pos:
                selected(pos + 1, r)
            else:
                selected(l, pos - 1)

        selected(0, len(arr) - 1)
        return arr[:k]
