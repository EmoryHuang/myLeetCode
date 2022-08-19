'''
Descroption: LeetCode 1705. ��ƻ���������Ŀ
Author: EmoryHuang
Date: 2021-12-24 09:04:16
Method:
ģ�� + ���ȶ���
ά��һ��С���ѣ��ֱ�洢ÿ���ժ��Ϣ (days[i], apples[i], pickday)
ÿ��Ҫ��ƻ��ʱ��ȡ�Ѷ�Ԫ�أ�ֱ���Ѷ���ƻ�����Ǹ��õ�
����󣬸��µ� pickday ���ƻ������
'''


class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        heap = []
        ans, i = 0, 0
        while heap or i < len(days):
            eat = False
            if i < len(days) and apples[i] != 0:
                # ά��һ��С���ѣ��ֱ�洢ÿ���ժ��Ϣ (days[i] + pickday, apples[i])
                heapq.heappush(heap, (days[i] + i, apples[i]))
            while heap and not eat:
                # ȡ�Ѷ�Ԫ�أ�ֱ���Ѷ���ƻ�����Ǹ��õ�
                day, apple = heapq.heappop(heap)
                # ���ƻ���Ƿ���
                if i >= day:
                    continue
                ans += 1
                eat = True
                # ���µ� pick ���ƻ������
                if apple - 1 != 0:
                    heapq.heappush(heap, (day, apple - 1))
            i += 1
        return ans
