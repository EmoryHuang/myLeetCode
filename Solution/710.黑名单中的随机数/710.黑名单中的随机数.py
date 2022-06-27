'''
Descroption: LeetCode 710. �������е������
Author: EmoryHuang
Date: 2022-06-25 10:59:54
Method:
������ [0,n-m) ��Χ�ڵĺ������������Խ���ӳ�䵽 [n-m,n) ��Χ�ڵķǺ���������������������
'''


class Solution:
    def __init__(self, n: int, blacklist: List[int]):
        # �ֽ��
        self.seq = w = n - len(blacklist)
        # �ֽ���ĺ���������
        black = {b for b in blacklist if b >= self.seq}
        # ����������������ӳ��
        self.b2w = {}
        # ���ڷֽ��֮ǰ�ĺ��������֣�����ӳ�䵽�ֽ���Ǻ�����������
        for b in blacklist:
            if b < self.seq:
                while w in black:
                    w += 1
                self.b2w[b] = w
                w += 1

    def pick(self) -> int:
        x = random.randrange(self.seq)
        return self.b2w.get(x, x)


# Your Solution object will be instantiated and called as such:
# obj = Solution(n, blacklist)
# param_1 = obj.pick()