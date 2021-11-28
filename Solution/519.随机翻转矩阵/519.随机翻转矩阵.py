'''
Descroption: LeetCode 519. �����ת����
Author: EmoryHuang
Date: 2021-11-27 08:44:42
Method:
���ѡȡ������Ϊһά���������λ�ã�ʹ�ü��ϼ�¼��ת����Ԫ��λ�ã�����ѡ���λ���Ѿ������������ѡ��
'''


class Solution:
    def __init__(self, m: int, n: int):
        self.m = m
        self.n = n
        self.s = set()

    def flip(self) -> List[int]:
        # ���ѡȡ������Ϊ����
        idx = random.randint(0, self.m * self.n - 1)
        while idx in self.s:
            idx = random.randint(0, self.m * self.n - 1)
        self.s.add(idx)
        return [idx // self.n, idx % self.n]

    def reset(self) -> None:
        self.s.clear()


# Your Solution object will be instantiated and called as such:
# obj = Solution(m, n)
# param_1 = obj.flip()
# obj.reset()