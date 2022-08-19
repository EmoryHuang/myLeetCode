'''
Descroption: LeetCode 2045. ����Ŀ�ĵصĵڶ���ʱ��
Author: EmoryHuang
Date: 2022-01-24 18:22:20
Method:
BFS
ͬʱά�����·�ʹζ�·���� d < min_d[x]�������� min_d[x] ���� sec_d[x]������ d ���� min_d[x]
�� min_d[x] < d < sec_d[x]������ d ���� sec_d[x]
���ں��̵Ƶ��л�����: ���� step ��
�� step % change Ϊ�棬��Ϊ��ƣ��ȴ�ʱ��Ϊ change - (step % change)
�� step % change Ϊż����Ϊ�̵ƣ��ȴ�ʱ��Ϊ 0 
'''


class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int,
                      change: int) -> int:
        mmap = defaultdict(list)
        for i, j in edges:
            mmap[i].append(j)
            mmap[j].append(i)
        # min_d �� sec_d �ֱ��ʾ�� 1 �� i ����С�͵ڶ�С��·������
        min_d, sec_d = [float('inf')] * (n + 1), [float('inf')] * (n + 1)
        min_d[1] = 0
        q = deque([(1, 0)])
        while q:
            u, dis = q.popleft()
            for v in mmap[u]:
                d = dis + 1
                if d < min_d[v]:
                    sec_d[v] = min_d[v]
                    min_d[v] = d
                    q.append((v, min_d[v]))
                    q.append((v, sec_d[v]))
                elif min_d[v] < d < sec_d[v]:
                    sec_d[v] = d
                    q.append((v, sec_d[v]))
        ans = 0
        for i in range(sec_d[n]):
            a, b = ans // change, ans % change
            wait = 0 if a % 2 == 0 else change - b
            ans += time + wait
        return ans