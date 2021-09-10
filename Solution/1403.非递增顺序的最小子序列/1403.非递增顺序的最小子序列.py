'''
Descroption: LeetCode 1403. �ǵ���˳�����С������
Author: EmoryHuang
Date: 2021-06-05 14:55:00
����˼·:
̰��˼�룬���Ƚ� nums ��������
Ȼ��Ӵ�Сѡ��Ԫ�أ������������е�Ԫ��֮�ʹ���ʣ��Ԫ�أ����ҵ�
'''


class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        sub = []
        for num in sorted(nums, reverse=True):
            sub.append(num)
            if(sum(sub) > sum(nums) - sum(sub)):
                return sub
