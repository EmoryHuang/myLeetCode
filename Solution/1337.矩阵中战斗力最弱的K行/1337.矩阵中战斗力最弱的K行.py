'''
Descroption: LeetCode 1337. 矩阵中战斗力最弱的 K 行
Author: EmoryHuang
Date: 2021-08-01 12:40:42
Method:
二分 + 最小堆
由于 1 总是出现在 0 之前，那么使用二分法寻找右端点，找到每行1的个数
然后建立最小堆，找到前k个最小值对应的行
'''


class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        m, n = len(mat), len(mat[0])
        power = []
        for i, row in enumerate(mat):
            l, r = 0, n - 1
            while l < r:
                mid = l + r + 1 >> 1
                if row[mid] == 1:
                    l = mid
                else:
                    r = mid - 1
            l = l + 1 if row[l] == 1 else l
            power.append([l, i])
        ans = []
        heapq.heapify(power)
        for i in range(k):
            ans.append(heapq.heappop(power)[1])
        return ans
