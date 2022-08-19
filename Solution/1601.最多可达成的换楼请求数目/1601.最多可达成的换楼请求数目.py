'''
Descroption: LeetCode 1601. ���ɴ�ɵĻ�¥������Ŀ
Author: EmoryHuang
Date: 2022-02-28 08:53:14
Method:
������ö��
ʹ�ö�����λ��¼ѡ��¥������������л�¥����
ͳ�ƶ��������� 1 �ĸ��������жϵ�ǰ state �Ƿ�������㻻¥����
'''


class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        # �жϵ�ǰ���Ƿ�������㻻¥����
        def check(state):
            cnt = [0] * 20
            for i, (x, y) in enumerate(requests):
                if (state >> i) & 1 == 1:
                    cnt[x] += 1
                    cnt[y] -= 1
            return all(x == 0 for x in cnt)

        ans = 0
        # �������л�¥����
        for state in range(1 << len(requests)):
            # ͳ�ƶ��������� 1 �ĸ���
            cnt = state.bit_count()
            if cnt <= ans:
                continue
            if check(state):
                ans = max(ans, cnt)
        return ans
