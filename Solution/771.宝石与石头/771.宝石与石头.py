'''
Descroption: LeetCode 771. ��ʯ��ʯͷ
Author: EmoryHuang
Date: 2021-08-25 15:43:55
Method:
���⣬��ϣ�����
'''


class Solution:
    # def numJewelsInStones(self, jewels: str, stones: str) -> int:
    #     ans = 0
    #     c = Counter(stones)
    #     for key, val in c.items():
    #         if key in jewels:
    #             ans += val
    #     return ans

    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return sum(s in jewels for s in stones)