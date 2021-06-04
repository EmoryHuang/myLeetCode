'''
Descroption: LeetCode 950. 按递增顺序显示卡牌
Author: EmoryHuang
Date: 2021-06-04 14:47:00
解题思路:
按照模拟的方法，对于题目给我们的规则，可以倒着思考
从大到小对卡牌进行排序
首先将最大的节点放入卡堆（此时卡堆只有一张牌），然后将卡堆底部的牌放到顶部
然后再在卡堆的顶部放上下一张牌
这样，在按照题目规则进行的时候，我们就可以得到递增顺序的卡牌
'''


class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        q = deque()
        for card in sorted(deck, reverse=True):
            if len(q) == 0:
                q.append(card)  # 最大的节点入队
            else:
                q.appendleft(q.pop())  # 队尾元素放到队头
                q.appendleft(card)  # 加入下一个元素
        return list(q)
