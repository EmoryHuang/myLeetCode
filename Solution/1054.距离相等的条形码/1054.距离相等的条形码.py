'''
Descroption: LeetCode 1054. 距离相等的条形码
Author: EmoryHuang
Date: 2021-09-07 20:13:44
Method:
方法一：直接排序
先用哈希表统计元素的数量，并从大到小进行排序
然后隔位插入，按元素的频次大小顺序，将元素隔位插入
方法二：堆
与方法一类似，不同的就是不直接排序而使用大根堆
'''


class Solution:
    # 方法一：直接排序
    # def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
    #     n = len(barcodes)
    #     order = sorted([(val, key) for key, val in Counter(barcodes).items()],
    #                    reverse=True)
    #     cur = []
    #     # 频次大到小的元素
    #     for val, key in order:
    #         cur += [key] * val
    #     j = 0
    #     ans = [0] * n
    #     # 按元素的频次大小顺序，将元素隔位插入
    #     for i in range(0, n, 2):
    #         ans[i] = cur[j]
    #         j += 1
    #     for i in range(1, n, 2):
    #         ans[i] = cur[j]
    #         j += 1
    #     return ans

    # 方法二：堆
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        n = len(barcodes)
        # python 是小根堆
        order = [(-val, key) for key, val in Counter(barcodes).items()]
        heapq.heapify(order)
        cur = []
        while order:
            val, key = heapq.heappop(order)
            # 频次大到小的元素
            cur += [key] * -val
        j = 0
        ans = [0] * n
        # 按元素的频次大小顺序，将元素隔位插入
        for i in range(0, n, 2):
            ans[i] = cur[j]
            j += 1
        for i in range(1, n, 2):
            ans[i] = cur[j]
            j += 1
        return ans
