'''
Descroption: LeetCode 849. ��������˵�������
Author: EmoryHuang
Date: 2021-06-13 15:07:00
����˼·:
Ѱ���������0����ͷβ�������⴦��
'''


class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        start, ans = -1, 0
        for i in range(len(seats)):
            if seats[i] == 1:
                if start == -1:  # ��һ����
                    ans = i
                else:
                    ans = max(ans, int((i - start) / 2))
                start = i
        ans = max(len(seats) - start - 1, ans)  # ���һ����
        return ans
