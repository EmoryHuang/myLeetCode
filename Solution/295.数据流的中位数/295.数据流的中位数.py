'''
Descroption: LeetCode 295. 数据流的中位数
Author: EmoryHuang
Date: 2021-08-27 13:29:58
Method:
使用两个优先队列（堆）来维护整个数据流数据，
维护数据流左半边数据的优先队列（堆）为 l，维护数据流右半边数据的优先队列（堆）为 r
l 为大根堆，r 为小根堆
当数据流元素数量为偶数：l 和 r 大小相同，此时动态中位数为两者堆顶元素的平均值；
当数据流元素数量为奇数：l 比 r 多一，此时动态中位数为 l 的堆顶原数。
'''


class MedianFinder:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.l = []  # 大根堆
        self.r = []  # 小根堆

    def addNum(self, num: int) -> None:
        l, r = self.l, self.r
        # 如果l为空，或者num小于等于左半部分最大值
        if not l or -l[0] >= num:
            heapq.heappush(l, -num)
            # 若左右部分的相差的数字个数大于1
            if len(r) + 1 < len(l):
                # 将左半部分的最大值放到右半部分
                heapq.heappush(r, -heapq.heappop(l))
        else:
            heapq.heappush(r, num)
            if len(r) > len(l):
                heapq.heappush(l, -heapq.heappop(r))

    def findMedian(self) -> float:
        l, r = self.l, self.r
        if len(l) > len(r):
            return -l[0]
        return (-l[0] + r[0]) / 2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()