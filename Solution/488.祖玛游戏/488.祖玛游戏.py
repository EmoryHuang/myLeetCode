'''
Descroption: LeetCode 488. ������Ϸ
Author: EmoryHuang
Date: 2021-11-09 16:00:38
Method:
dfs + ��֦
���ѣ������������Լ����Բ����ÿ��λ�ã�����С�Ĳ������
ʹ��һ�� int ����¼ hand ��ʹ�����
'''


class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        def dfs(cur: str, use: int):
            if len(cur) == 0:
                return 0
            if cur in hash:
                return hash[cur]

            ans, n = float('inf'), len(cur)
            # �������п����ַ�
            for i in range(len(hand)):
                # �����ǰλ�Ѿ�ʹ�ù�
                if (use >> i) & 1:
                    continue
                # ��һ��״̬
                next = (1 << i) | use
                # �������пɲ���λ��
                for j in range(n + 1):
                    if 0 < j < n - 1 and cur[j] == cur[j - 1]:
                        continue
                    if 0 < j < n - 1 and cur[j] != hand[i]:
                        continue
                    s = cur[:j] + hand[i]
                    # ����������һ��λ��
                    if j != n:
                        s += cur[j:]
                    k = j
                    while 0 <= k < len(s):
                        l, r = k, k
                        # �Ӳ���λ������������������ 3 �����ַ�
                        while l >= 0 and s[l] == s[k]:
                            l -= 1
                        while r < len(s) and s[r] == s[k]:
                            r += 1
                        if r - l - 1 >= 3:
                            s = s[:l + 1] + s[r:]
                            k = l if l >= 0 else r
                        else:
                            break
                    ans = min(ans, dfs(s, next) + 1)
            hash[cur] = ans
            return ans

        hash = defaultdict(int)
        res = dfs(board, 1 << len(hand))
        if res == float('inf'):
            return -1
        return res
