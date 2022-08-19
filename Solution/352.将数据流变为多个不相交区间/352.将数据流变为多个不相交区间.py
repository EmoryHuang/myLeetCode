'''
Descroption: LeetCode 352. 将数据流变为多个不相交区间
Author: EmoryHuang
Date: 2021-10-09 19:31:48
Method:
并查集
使用并查集记录当前区间的右端点
并维护一个 set 记录区间的起点
在合并并查集时，若属于同一个人区间，则从起点中删除后面的节点
'''


class SummaryRanges:
    def __init__(self):
        # 初始化并查集
        self.parent = [-1] * 10001
        # 记录起点位置
        self.s = set()

    def find(self, x: int):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x: int, y: int):
        if 0 <= x <= 10000 and 0 <= y <= 10000 and self.parent[x] != -1 and self.parent[y] != -1:
            px, py = self.find(x), self.find(y)
            if px != py:
                self.parent[px] = py
                # 删除起点位置
                self.s.remove(y)

    def addNum(self, val: int) -> None:
        if self.parent[val] == -1:
            self.parent[val] = val
            self.s.add(val)
            self.union(val, val + 1)
            self.union(val - 1, val)

    def getIntervals(self) -> List[List[int]]:
        ans = []
        for start in sorted(self.s):
            # 找到终点位置
            end = self.find(start)
            ans.append([start, end])
        return ans


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()