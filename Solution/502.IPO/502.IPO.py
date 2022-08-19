'''
Descroption: LeetCode 502. IPO
Author: EmoryHuang
Date: 2021-09-08 15:09:49
Method:
��
����ʱ�ʱ�����ǲ���Ҫ��ȥ�����ʽ�ֻ��Ҫ���Ǵ�����
����˼���������ģ����ȣ����ǰ������ʽ��С�����������
����ѡ��k����Ŀ����ѡ����Ŀʱ�������е������ʽ𲻳��� w ����Ŀ�������ȶ���
ѡ�����������Ǹ���Ŀ����
'''


class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int],
                             capital: List[int]) -> int:
        # �������ʽ��С�����������
        p = sorted(zip(capital, profits), key=lambda x: x[0])
        pick = []
        i = 0
        for _ in range(k):
            # �����е������ʽ𲻳��� w ������������ȶ���
            while i < len(profits) and p[i][0] <= w:
                heapq.heappush(pick, -p[i][1])
                i += 1
            if not pick:  # ����Ϊ��
                break
            # �Ӷ�����ѡ������������Ŀ
            w -= heapq.heappop(pick)
        return w