'''
Descroption: LeetCode 846. һ��˳��
Author: EmoryHuang
Date: 2021-07-15 19:49:23
����˼·:
�ù�ϣ���¼����Ԫ�ص�����
��������Ԫ�ؽ��б���������ÿ��Ԫ�� num
�� num + i �ĸ���Ϊ0���򷵻� false
'''


class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        n = len(hand)
        if n % groupSize != 0:
            return False
        hand.sort()
        mp = defaultdict(int)
        for num in hand:
            mp[num] += 1
        for num in hand:
            if mp[num] == 0:
                continue
            for i in range(groupSize):
                if num + i not in mp:
                    return False
                mp[num + i] -= 1
        return True
