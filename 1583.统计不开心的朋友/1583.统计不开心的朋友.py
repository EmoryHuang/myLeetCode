'''
Descroption: LeetCode 1583. ͳ�Ʋ����ĵ�����
Author: EmoryHuang
Date: 2021-08-14 13:46:59
Method:
ģ��
��� y �� x ���׽��̶ȵ��±겢��¼������
����ÿ���� x, ��� x ����� y �Լ� y �� x �����̶ܳȴ��� index
����ÿ�����ܵ� u��0 ~ index - 1���ҵ������� u ��Ե����� v
��� u �� x ���׽��̶�ʤ�� u �� v���� x ������
'''


class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]],
                       pairs: List[List[int]]) -> int:
        # ��� y �� x ���׽��̶ȵ��±�
        order = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n - 1):
                order[i][preferences[i][j]] = j
        # ��¼������
        pair = [0] * n
        for x, y in pairs:
            pair[x] = y
            pair[y] = x
        ans = 0
        for x in range(n):
            # ��� x ����� y �Լ� y �� x �����̶ܳȴ���
            y = pair[x]
            index = order[x][y]
            for i in range(index):
                # ����ÿ�����ܵ� u���ҵ������� u ��Ե����� v
                u = preferences[x][i]
                v = pair[u]
                # ��� u �� x ���׽��̶�ʤ�� u �� v
                if order[u][x] < order[u][v]:
                    ans += 1
                    break
        return ans
