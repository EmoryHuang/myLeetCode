'''
Descroption: LeetCode 1834. ���߳� CPU
Author: EmoryHuang
Date: 2021-09-11 19:42:08
Method:
���� + С����
�����е�������ӱ�Ų�������ʱ������
ά��һ��С����
����ǰʱ�� >= ����Ŀ�Ŀ�ʼʱ�䣬�����п���ִ�е���Ŀ���
���û����Ŀ����ִ�У����޸ĵ�ǰʱ��Ϊ�¸�����Ŀ�ʼʱ��
'''


class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        n = len(tasks)
        tasks = [[ent, dur, idx] for idx, (ent, dur) in enumerate(tasks)]  # ������
        # ������ʱ������
        tasks.sort(key=lambda x: x[0])
        ans, heap = [], []
        cur_t, cur_id = tasks[0][0], 0
        while len(ans) < n:
            # ����ǰʱ�� >= ����Ŀ�Ŀ�ʼʱ��
            # �����п���ִ�е���Ŀ�������
            while cur_id < n and cur_t >= tasks[cur_id][0]:
                ent, dur, idx = tasks[cur_id]
                heapq.heappush(heap, [dur, idx, ent])
                cur_id += 1
            if not heap:
                # ���û����Ŀ����ִ�У����޸ĵ�ǰʱ��Ϊ�¸�����Ŀ�ʼʱ��
                cur_t = tasks[cur_id][0]
                continue
            # ִ����Ŀ
            [dur, idx, ent] = heapq.heappop(heap)
            ans.append(idx)
            cur_t += dur
        return ans
