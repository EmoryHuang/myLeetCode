'''
Descroption: LeetCode 785. �ж϶���ͼ
Author: EmoryHuang
Date: 2021-08-02 15:15:33
Method:
Ⱦɫ���ж϶���ͼ
��������ѡȡһ��δȾɫ�ĵ����Ⱦɫ��Ȼ���Խ������ڵĵ�Ⱦ���෴����ɫ��
����ڽӵ��Ѿ���Ⱦɫ�������е�Ⱦɫ����Ӧ�ñ�Ⱦ����ɫ��ͬ����ô��˵�����Ƕ���ͼ
'''


class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        # 0��ʾδȾɫ��1��ʾ��ɫ��2��ʾ��ɫ
        color = [0] * n

        def dfs(u: int, c: int) -> bool:
            # u��ʾ��ǰ�ڵ㣬c��ʾ��ǰ�����ɫ
            color[u] = c
            # ����u���ڽӽڵ�
            for i in range(len(graph[u])):
                v = graph[u][i]
                # ������ڽڵ�δȾɫ
                if color[v] == 0:
                    # �����ڵĵ�Ⱦ���෴����ɫ
                    if not dfs(v, 3 - c):
                        return False
                elif color[v] == c:
                    # ���v�Ѿ���ɫ���Һͽ��u��ɫ��ͻ
                    return False
            return True

        flag = True
        for i in range(n):
            # �����ǰ�ڵ�δȾɫ
            if color[i] == 0:
                if not dfs(i, 1):
                    flag = False
                    break
        return flag