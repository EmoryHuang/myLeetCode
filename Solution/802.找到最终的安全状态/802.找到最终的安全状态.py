'''
Descroption: LeetCode 802. �ҵ����յİ�ȫ״̬
Author: EmoryHuang
Date: 2021-08-05 14:10:30
Method:
����ͼ + ��������
ͳ��ÿ���ڵ�ĳ��ȣ�����ͼ�洢Ϊ����ͼ
���Ƚ�����Ϊ 0 �Ľڵ����
ͨ���������򣬲���ȥ���ߣ�Ȼ�󽫳���Ϊ 0 �Ľڵ����
���ͳ�Ƴ���Ϊ 0 �Ľڵ�
'''


class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        mp = defaultdict(list)
        outdegree = [0] * n
        q = deque()
        for i, nodes in enumerate(graph):
            # ͳ�����нڵ�ĳ���
            outdegree[i] = len(nodes)
            if not outdegree[i]:
                # ������Ϊ 0 �Ľڵ����
                q.append(i)
            else:
                # ��������ͼ
                for node in nodes:
                    mp[node].append(i)
        # ��������
        while q:
            node = q.popleft()
            for ne in mp[node]:
                outdegree[ne] -= 1
                if not outdegree[ne]:
                    q.append(ne)
        # ͳ�Ƴ���Ϊ 0 �Ľڵ�
        return [i for i in range(n) if not outdegree[i]]
