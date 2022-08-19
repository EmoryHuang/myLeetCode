'''
Descroption: LeetCode 847. �������нڵ�����·��
Author: EmoryHuang
Date: 2021-08-06 15:15:58
Method:
BFS + ״̬ѹ��
Ϊ�˱�ʶ���еķ���״̬��ʹ��״̬ѹ������һλ��ʾһ���ڵ��Ƿ����
����Ϊ����ʱ��mask = (000) = 0����������ʱ��mask = (111) = 2^n - 1
ͬ���ģ����µ� i ���ڵ��״̬ʱ��next_mask = mask | (1 << i)
�ص���Ŀ��һ��ʼ��������㲻ȷ������˽����нڵ�����
ʹ��BFS���ж�����ı���
'''


class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        # ������㲻ȷ�������visΪn��2^n�У��Լ�¼ÿ����״̬
        vis = [[False] * (1 << n) for _ in range(n)]
        q = deque()
        for i in range(n):
            # ���ڵ����id��״̬mask�;���dis���
            # ״̬maskʹ��λ��ʶÿ���ڵ��Ƿ����
            q.append([i, 1 << i, 0])
            vis[i][1 << i] = True
        while q:
            id, mask, dis = q.popleft()
            # ����Ѿ�������ȫ���ڵ㣬��״̬Ϊ 2^n - 1
            if mask == (1 << n) - 1:
                return dis
            for ne in graph[id]:
                next_mask = mask | (1 << ne)  # ������õ���һ��״̬
                if not vis[ne][next_mask]:
                    q.append([ne, next_mask, dis + 1])
                    vis[ne][next_mask] = True
        return 0
