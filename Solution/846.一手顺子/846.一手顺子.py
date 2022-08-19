'''
Descroption: LeetCode 846. 一手顺子
Author: EmoryHuang
Date: 2021-07-15 19:49:23
解题思路:
用哈希表记录各个元素的数量
对排序后的元素进行遍历，对于每个元素 num
若 num + i 的个数为0，则返回 false
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
