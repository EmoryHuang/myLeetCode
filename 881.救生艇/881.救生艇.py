'''
Descroption: LeetCode 881. ����ͧ
Author: EmoryHuang
Date: 2021-07-21 20:16:19
����˼·:
˫ָ�� + ̰��
�������ߺ����ұߵ������ϴ�����ô�������˾���
�������ߺ����ұߵ��˲����ϴ������ұߵ��˵�����
'''


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        cnt = 0
        l, r = 0, len(people) - 1
        while l <= r:
            if people[l] + people[r] <= limit:
                # �������ߺ����ұߵ������ϴ�
                l += 1
                r -= 1
                cnt += 1
            else:
                # �������ߺ����ұߵ��˲����ϴ������ұߵ��˵�����
                r -= 1
                cnt += 1
        return cnt
