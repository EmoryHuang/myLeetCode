'''
Descroption: LeetCode 295. ����������λ��
Author: EmoryHuang
Date: 2021-08-27 13:29:58
Method:
ʹ���������ȶ��У��ѣ���ά���������������ݣ�
ά���������������ݵ����ȶ��У��ѣ�Ϊ l��ά���������Ұ�����ݵ����ȶ��У��ѣ�Ϊ r
l Ϊ����ѣ�r ΪС����
��������Ԫ������Ϊż����l �� r ��С��ͬ����ʱ��̬��λ��Ϊ���߶Ѷ�Ԫ�ص�ƽ��ֵ��
��������Ԫ������Ϊ������l �� r ��һ����ʱ��̬��λ��Ϊ l �ĶѶ�ԭ����
'''


class MedianFinder:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.l = []  # �����
        self.r = []  # С����

    def addNum(self, num: int) -> None:
        l, r = self.l, self.r
        # ���lΪ�գ�����numС�ڵ�����벿�����ֵ
        if not l or -l[0] >= num:
            heapq.heappush(l, -num)
            # �����Ҳ��ֵ��������ָ�������1
            if len(r) + 1 < len(l):
                # ����벿�ֵ����ֵ�ŵ��Ұ벿��
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