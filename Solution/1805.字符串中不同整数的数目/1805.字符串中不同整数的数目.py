'''
Descroption: LeetCode 1805. �ַ����в�ͬ��������Ŀ
Author: EmoryHuang
Date: 2021-07-14 20:45:41
����˼·:
�������飬���������֣����¼
����ͬ�����ַ�������
'''


class Solution:
    # ����һ������
    # def numDifferentIntegers(self, word: str) -> int:
    #     nums = []
    #     num = ''
    #     for ch in word:
    #         if ch.isdigit():
    #             num += ch
    #         else:
    #             if num != '' and int(num) not in nums:
    #                 nums.append(int(num))
    #             num = ''
    #     if num != '' and int(num) not in nums:
    #         nums.append(num)
    #     return len(nums)

    # ������������
    def numDifferentIntegers(self, word: str) -> int:
        return len(set(int(each) for each in re.findall(r"([0-9]+)", word)))
