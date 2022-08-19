'''
Descroption: LeetCode 528. ��Ȩ�����ѡ��
Author: EmoryHuang
Date: 2021-08-30 22:03:43
Method:
ǰ׺�� + ����
ÿ��Ԫ�ش���һ��Ȩ�أ�����Խ���Ԫ�أ�����Ȩ��Խ��
����ʹ��ǰ׺����������ΪȨ�طֲ�����
�������ǰ׺�������в���
ͨ�������������ٶ�λ��������±꼴��
'''


class Solution:
    def __init__(self, w: List[int]):
        n = len(w)
        self.pre = [0] * n
        self.pre[0] = w[0]
        # ����ǰ׺��
        for i in range(n):
            self.pre[i] = self.pre[i - 1] + w[i]

    def pickIndex(self) -> int:
        seed = random.randint(1, self.pre[-1])
        pre = self.pre
        n = len(pre)
        # ����Ѱ�ҵ�һ������ seed <= pre[i] ��Ԫ�� i
        l, r = 0, n - 1
        while l < r:
            mid = l + r >> 1
            if pre[mid] >= seed:
                r = mid
            else:
                l = mid + 1
        return l


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()