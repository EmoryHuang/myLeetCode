'''
Descroption: LeetCode 423. ��Ӣ�����ؽ�����
Author: EmoryHuang
Date: 2021-11-24 08:29:35
Method:
ģ��
z, w, u, x, g ��ֻ��һ�������г��֣��� 0, 2, 4, 6, 8 �г���
h ֻ�� 3, 8 �г��֣�f ֻ�� 4, 5 �г��֣�s ֻ�� 6, 7 �г���
o ֻ�� 0, 1, 2, 4 �г��֣�i ֻ�� 5, 6, 8, 9 �г���
'''


class Solution:
    def originalDigits(self, s: str) -> str:
        c = Counter(s)
        cnt = [0] * 10
        # z, w, u, x, g ��ֻ��һ�������г��֣��� 0, 2, 4, 6, 8 �г���
        cnt[0] = c['z']
        cnt[2] = c['w']
        cnt[4] = c['u']
        cnt[6] = c['x']
        cnt[8] = c['g']
        # h ֻ�� 3, 8 �г��֣�f ֻ�� 4, 5 �г��֣�s ֻ�� 6, 7 �г���
        cnt[3] = c['h'] - cnt[8]
        cnt[5] = c['f'] - cnt[4]
        cnt[7] = c['s'] - cnt[6]
        # o ֻ�� 0, 1, 2, 4 �г��֣�i ֻ�� 5, 6, 8, 9 �г���
        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4]
        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8]
        return ''.join(str(x) * cnt[x] for x in range(10))
