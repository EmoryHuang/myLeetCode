'''
Descroption: LeetCode 352. ����������Ϊ������ཻ����
Author: EmoryHuang
Date: 2021-10-09 19:31:48
Method:
���鼯
ʹ�ò��鼯��¼��ǰ������Ҷ˵�
��ά��һ�� set ��¼��������
�ںϲ����鼯ʱ��������ͬһ�������䣬��������ɾ������Ľڵ�
'''


class SummaryRanges:
    def __init__(self):
        # ��ʼ�����鼯
        self.parent = [-1] * 10001
        # ��¼���λ��
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
                # ɾ�����λ��
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
            # �ҵ��յ�λ��
            end = self.find(start)
            ans.append([start, end])
        return ans


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()