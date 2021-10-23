'''
Descroption: LeetCode 210. �γ̱� II
Author: EmoryHuang
Date: 2021-10-23 14:39:09
Method:
��������
ά��һ�����У������Ϊ 0 �Ľڵ���ӣ�Ȼ�������ӵĽڵ���ȼ�һ
ֱ������Ϊ��
'''


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        edges = defaultdict(list)
        indegree = [0] * numCourses
        # �����ڽӱ�
        for a, b in prerequisites:
            edges[b].append(a)
            indegree[a] += 1
        q = deque()
        # �����Ϊ 0 �Ľڵ����
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
        ans = []
        while q:
            u = q.popleft()
            ans.append(u)
            for v in edges[u]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    q.append(v)
        if len(ans) != numCourses:
            return []
        return ans
