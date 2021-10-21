'''
Descroption: LeetCode 985. ��ѯ���ż����
Author: EmoryHuang
Date: 2021-10-21 19:31:08
Method:
ģ��
����ԭ����ż���� s��������ѯ
���޸�ǰ��ż�������� s �м�ȥ
���޸ĺ�����ż��������������
'''


class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        # ����ԭ����ż����
        s = sum([num for num in nums if num % 2 == 0])
        ans = []
        for val, idx in queries:
            # ���޸�ǰ��ż�������� s �м�ȥ
            if nums[idx] % 2 == 0:
                s -= nums[idx]
            nums[idx] += val
            # ���޸ĺ�����ż��
            if nums[idx] % 2 == 0:
                s += nums[idx]
            ans.append(s)
        return ans