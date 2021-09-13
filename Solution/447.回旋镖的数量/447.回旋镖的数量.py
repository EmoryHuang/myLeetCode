'''
Descroption: LeetCode 447. 回旋镖的数量
Author: EmoryHuang
Date: 2021-09-13 11:03:11
Method:
暴力 + 哈希表
遍历当前点到其他点的距离，并用哈希表记录距离出现次数
从每个距离出现次数 n 中选出两个数，作为另外两个点
即 A(n, 2) = n * (n - 1)
'''


class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        ans = 0
        for a, b in points:
            hash = defaultdict(int)
            # 遍历当前点到其他点的距离
            for c, d in points:
                dis = (a - c)**2 + (b - d)**2
                hash[dis] += 1
            # 从每个距离出现次数 n 中选出两个数
            # 即 A(n, 2) = n * (n - 1)
            for n in hash.values():
                ans += n * (n - 1)
        return ans
