'''
Descroption: LeetCode 886. ���ܵĶ��ַ�
Author: EmoryHuang
Date: 2021-08-26 16:55:05
Method:
����һ�����鼯
����ÿ���ˣ������������ǲ�ϲ�����ˣ�����ϲ������������ͬһ�飬������
ͬʱ����ͬһ���˲�ϲ���ı�����ͬһ�飬���򲻻��Ƕ���ͼ

��������Ⱦɫ��
����ÿ����ͨ�Ĳ��֣���������ɫ����������ɫ���Ϳ��Լ�����Ƿ��Ƕ��ֵġ�
����һ���Ϳ�ɰ�ɫ��Ȼ�����������ھӶ�Ϳ�ɺ�ɫ��
Ȼ�����е��ھӵ��ھӶ�Ϳ�ɰ�ɫ���Դ����ơ�
��������ͻ��˵�����Ƕ���ͼ��
'''


class Solution:
    # ����һ�����鼯
    # def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
    #     def find(x: int) -> int:
    #         if x != parent[x]:
    #             parent[x] = find(parent[x])
    #         return parent[x]

    #     def merge(x: int, y: int) -> None:
    #         parent[find(x)] = find(y)

    #     # ��ʼ�����鼯
    #     parent = list(range(n + 1))
    #     # �����ڽӱ�
    #     mp = defaultdict(list)
    #     for a, b in dislikes:
    #         mp[a].append(b)
    #         mp[b].append(a)
    #     for i in range(1, n + 1):
    #         for j in mp[i]:
    #             # ����ϲ������������ͬһ�飬������
    #             if find(i) == find(j):
    #                 return False
    #             # ��ͬһ���˲�ϲ���ı�����ͬһ�飬���򲻻��Ƕ���ͼ
    #             merge(mp[i][0], j)
    #     return True

    # ��������Ⱦɫ��
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        def dfs(u: int, c: int) -> bool:
            # u��ʾ��ǰ�ڵ㣬c��ʾ��ǰ�����ɫ
            color[u] = c
            # ���� u ���ڽӽڵ�
            for v in mp[u]:
                # �����ǰ�ڵ�δȾɫ
                if not color[v]:
                    # �����ڵĵ�Ⱦ���෴����ɫ
                    if not dfs(v, -c): return False
                elif color[v] == c:
                    # ���v�Ѿ���ɫ���Һͽ��u��ɫ��ͻ
                    return False
            return True

        mp = defaultdict(list)
        for a, b in dislikes:
            mp[a].append(b)
            mp[b].append(a)
        # 0��ʾδȾɫ��1��ʾ��ɫ��-1��ʾ��ɫ
        color = [0] * (n + 1)
        flag = True
        for i in range(1, n + 1):
            # �����ǰ�ڵ�δȾɫ
            if not color[i]:
                if not dfs(i, 1):
                    flag = False
                    break
        return flag
