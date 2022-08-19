'''
Descroption: ��ָ Offer II 114. �������ֵ�
Author: EmoryHuang
Date: 2022-05-31 09:40:17
Method:
�������� + BFS
���ֵ��е�ÿ����ĸ����һ���ڵ㣬��ĸ֮���˳���ϵ��������ߣ����н�ͼ
���������Ϊ 0 �Ľڵ����
ʹ�� BFS ȡ�������еĽڵ㣬�������ӵĽڵ���ȼ� 1�����������Ϊ 0 �Ľڵ����
����л����򷵻ؿ��ַ���
'''


class Solution:
    def alienOrder(self, words: List[str]) -> str:
        g = defaultdict(list)
        indegree = defaultdict(int)
        for word in words:
            for ch in word:
                indegree[ch] = 0

        # ���ֵ��е�ÿ����ĸ����һ���ڵ㣬��ĸ֮���˳���ϵ���������
        for a, b in pairwise(words):
            for ca, cb in zip(a, b):
                if ca != cb:
                    g[ca].append(cb)
                    indegree[cb] += 1
                    break
            else:
                if len(a) > len(b):
                    return ""

        # ���������Ϊ 0 �Ľڵ�������
        q = deque([k for k, v in indegree.items() if v == 0])
        res = ''

        while q:
            node = q.popleft()
            res += node
            # �������
            for k in g[node]:
                indegree[k] -= 1
                if indegree[k] == 0:
                    q.append(k)
        # ����л����򷵻ؿ��ַ���
        return res if len(res) == len(indegree) else ''