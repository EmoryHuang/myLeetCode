'''
Descroption: LeetCode 630. �γ̱� III
Author: EmoryHuang
Date: 2021-12-13 14:12:20
Method:
̰��
���γ̰�����ʱ������ʹ�����ȶ��м�¼��ǰ�γ�ʱ��
�������ǰ�Ͽ���ʱ�䳬���˵�ǰ�γ̵����ʱ�䣬��ȡ�����ȶ����еĳ���ʱ����Ŀγ�
'''


class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        # ���γ̽�ֹʱ������
        courses.sort(key=lambda x: x[1])
        heap = []
        total = 0  # ��¼�γ���ʱ��
        for dur, la in courses:
            total += dur
            heapq.heappush(heap, -dur)
            # �����ǰ�Ͽ���ʱ�䳬���˵�ǰ�γ̵����ʱ��
            if (total > la):
                total -= -heapq.heappop(heap)
        return len(heap)
