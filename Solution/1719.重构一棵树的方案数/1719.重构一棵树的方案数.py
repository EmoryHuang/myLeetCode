'''
Descroption: LeetCode 1719. �ع�һ�����ķ�����
Author: EmoryHuang
Date: 2022-02-16 09:49:17
Method:
adj[x] �洢�ڵ� x ���������Ⱥͺ��
����Ѱ�Ҹ��ڵ㣬���ڵ���������Ⱥͺ������ĿΪ n - 1
����ÿ���ڵ� node���ҵ���ǰ�ڵ�ĸ��ڵ� parent
�� parent Ϊ���ڵ㣬����и��ڵ�������ϵ��Ŀ �� ����ڵ�������ϵ��Ŀ
parent �����Ⱥͺ���бض������� node �����Ⱥͺ������ parent ����
��������ȫ������˵��������
�� parent �� node �����Ⱥͺ����Ŀ��ͬ�����޷�ȷ�����ӹ�ϵ�����ܴ��ڶ��ֹ���
'''


class Solution:
    def checkWays(self, pairs: List[List[int]]) -> int:
        # adj[x] �洢�ڵ� x ���������Ⱥͺ��
        adj = defaultdict(set)
        for i, j in pairs:
            adj[i].add(j)
            adj[j].add(i)
        root = -1
        for node, neighb in adj.items():
            # Ѱ�Ҹ��ڵ㣬���ڵ���������Ⱥͺ������ĿΪ n - 1
            if len(neighb) == len(adj) - 1:
                root = node
                break
        # ���ڵ㲻���ڣ��򷵻� 0
        if root == -1:
            return 0
        ans = 1
        for node, neighb in adj.items():
            if node == root:
                continue
            # �ڵ�ǰ�ڵ� node �����Ⱥͺ����Ѱ�ҵ�ǰ�ڵ�ĸ��ڵ�
            # �� parent Ϊ���ڵ㣬����и��ڵ�������ϵ��Ŀ �� ����ڵ�������ϵ��Ŀ
            cur_degree = len(neighb)
            parent = -1
            parent_degree = float('inf')
            for n in neighb:
                if cur_degree <= len(adj[n]) < parent_degree:
                    parent = n
                    parent_degree = len(adj[n])
            if parent == -1:
                return 0
            # ȷ�� node ���������Ⱥͺ����ϵ�Ƿ����
            # parent �����Ⱥͺ���бض������� node �����Ⱥͺ������ parent ����
            for n in neighb:
                if n == parent:
                    continue
                # ��������ȫ������˵��������
                if n not in adj[parent]:
                    return 0
            # �޷�ȷ�����ӹ�ϵ�����ܴ��ڶ��ֹ���
            if cur_degree == parent_degree:
                ans = 2
        return ans