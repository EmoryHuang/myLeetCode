'''
Descroption: ��ָ Offer 39. �����г��ִ�������һ�������
Author: EmoryHuang
Date: 2021-07-03 15:21:26
����˼·:
����һ�������ȡ��λ��
�������ֵĳ��ִ�������һ�룬�����λ��һ���������
����������ϣ��
'''


class Solution:
    # ����һ�������ȡ��λ��
    def majorityElement(self, nums: List[int]) -> int:
        return sorted(nums)[len(nums)//2]

    # ����������ϣ��
    # def majorityElement(self, nums: List[int]) -> int:
    #     return max( collections.Counter(nums).items() ,key= lambda x : x[1] )[0]
