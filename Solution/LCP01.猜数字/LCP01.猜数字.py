'''
Descroption: LCP 01. ������
Author: EmoryHuang
Date: 2021-07-08 18:42:37
����˼·:
���⣬����һ��
'''


class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        ans = 0
        for i in range(3):
            if guess[i] == answer[i]:
                ans += 1
        return ans
