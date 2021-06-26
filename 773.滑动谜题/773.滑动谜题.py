'''
Descroption: LeetCode 773. ��������
Author: EmoryHuang
Date: 2021-06-26 13:43:00
����˼·:
BFS
�� board �����ַ�����������Ҫ�õ��� target = "123450"
�ڵ�ǰ״̬ cur ���ҳ� 0 ���ڵ�λ�� x������ÿһ���� x ���ڵ�λ�� y��
���ǽ� cur[x] �� cur[y] ���н������õ���һ���µ�״̬ next
���������
'''


class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        neighbor = [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]]
        target, start = "123450", ""  # Ŀ��״̬
        # �õ���ʼ�ַ���
        for row in board:
            for s in row:
                start += str(s)
        if start == target:
            return 0
        q = deque([(start, 0)])  # ��¼����ǰ״̬��Ҫ step ��
        vis = {start}  # ��¼��ǰ�ַ����Ƿ����
        while q:
            cur, step = q.popleft()
            if cur == target:  # �ﵽĿ��״̬
                return step
            x = cur.index('0')  # �ҵ� 0 ��λ�� x
            for y in neighbor[x]:
                next = list(cur)
                next[y], next[x] = next[x], next[y]  # ����
                next = "".join(next)
                if next not in vis:  # next δ����
                    vis.add(next)
                    q.append((next, step + 1))
        return -1
