'''
Descroption: LeetCode 2013. ���������
Author: EmoryHuang
Date: 2022-01-26 11:06:28
Method:
ʹ�ù�ϣ��洢�� {x, {y: ��(x, y)���ִ���}}
����ĵ�Ϊ (x, y)���Ȳ�ѯ x �ж�����Щ�У���ö�ٵ� (x, ny)
�ɴ˿��Եõ������α߳� d
������Ѱ�� (x �� d, y) �� (x �� d, ny)
Ӧ�ó˷�ԭ������֪���������εķ�����
'''

class DetectSquares:
    def __init__(self):
        self.map = defaultdict(Counter)

    def add(self, point: List[int]) -> None:
        x, y = point
        self.map[x][y] += 1

    def count(self, point: List[int]) -> int:
        ans = 0
        x, y, = point
        if x not in self.map:
            return 0
        xcnt = self.map[x]
        for c, ccnt in self.map.items():
            if c != x:
                d = c - x  # �߳�
                # �˷�ԭ��������г��ִ���
                ans += ccnt[y] * ccnt[y + d] * xcnt[y + d]
                ans += ccnt[y] * ccnt[y - d] * xcnt[y - d]
        return ans


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)