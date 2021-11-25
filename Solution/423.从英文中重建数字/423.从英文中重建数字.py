'''
Descroption: LeetCode 423. 从英文中重建数字
Author: EmoryHuang
Date: 2021-11-24 08:29:35
Method:
模拟
z, w, u, x, g 都只在一个数字中出现，即 0, 2, 4, 6, 8 中出现
h 只在 3, 8 中出现，f 只在 4, 5 中出现，s 只在 6, 7 中出现
o 只在 0, 1, 2, 4 中出现，i 只在 5, 6, 8, 9 中出现
'''


class Solution:
    def originalDigits(self, s: str) -> str:
        c = Counter(s)
        cnt = [0] * 10
        # z, w, u, x, g 都只在一个数字中出现，即 0, 2, 4, 6, 8 中出现
        cnt[0] = c['z']
        cnt[2] = c['w']
        cnt[4] = c['u']
        cnt[6] = c['x']
        cnt[8] = c['g']
        # h 只在 3, 8 中出现，f 只在 4, 5 中出现，s 只在 6, 7 中出现
        cnt[3] = c['h'] - cnt[8]
        cnt[5] = c['f'] - cnt[4]
        cnt[7] = c['s'] - cnt[6]
        # o 只在 0, 1, 2, 4 中出现，i 只在 5, 6, 8, 9 中出现
        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4]
        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8]
        return ''.join(str(x) * cnt[x] for x in range(10))
