'''
Descroption: LeetCode 881. ����ͧ
Author: EmoryHuang
Date: 2021-08-26 15:53:48
Method:
˫ָ�� + ����
���ȶ������������ά������ָ��l��r���ֱ�ָ��ͷβ
�� people[l] + people[r] <= limit ˵���ܹ���2�ˣ�ָ��ֱ����ң��������
����people[r] ��Ҫ�������Ŵ�����ָ�������ƶ�
'''


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        ans, l, r = 0, 0, len(people) - 1
        while l <= r:
            if people[l] + people[r] <= limit:
                l += 1
            r -= 1
            ans += 1
        return ans
