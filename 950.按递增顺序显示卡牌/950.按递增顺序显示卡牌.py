'''
Descroption: LeetCode 950. ������˳����ʾ����
Author: EmoryHuang
Date: 2021-06-04 14:47:00
����˼·:
����ģ��ķ�����������Ŀ�����ǵĹ��򣬿��Ե���˼��
�Ӵ�С�Կ��ƽ�������
���Ƚ����Ľڵ���뿨�ѣ���ʱ����ֻ��һ���ƣ���Ȼ�󽫿��ѵײ����Ʒŵ�����
Ȼ�����ڿ��ѵĶ���������һ����
�������ڰ�����Ŀ������е�ʱ�����ǾͿ��Եõ�����˳��Ŀ���
'''


class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        q = deque()
        for card in sorted(deck, reverse=True):
            if len(q) == 0:
                q.append(card)  # ���Ľڵ����
            else:
                q.appendleft(q.pop())  # ��βԪ�طŵ���ͷ
                q.appendleft(card)  # ������һ��Ԫ��
        return list(q)
