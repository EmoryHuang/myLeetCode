'''
Descroption: LeetCode 229. ������ II
Author: EmoryHuang
Date: 2021-10-22 09:08:10
Method:
����һ����ϣ��
ʹ�ù�ϣ���¼Ԫ������

��������Ħ��ͶƱ��
�� 169. ����Ԫ�� ����
���ִ������� n / k �������ֻ�� k - 1 ��

Ħ��ͶƱ��: ÿ�δ�������ѡ����������ͬ������ɾ���������Ϊ������������
���ʣ��һ�����ֻ򼸸���ͬ�����֣����ǳ��ִ��������ܡ���������һ����Ǹ�
'''


class Solution:
    # ����һ����ϣ��
    # def majorityElement(self, nums: List[int]) -> List[int]:
    #     n = len(nums)
    #     ans = []
    #     hash = Counter(nums)
    #     for key, val in hash.items():
    #         if val > n // 3:
    #             ans.append(key)
    #     return ans

    # ��������Ħ��ͶƱ��
    def majorityElement(self, nums: List[int]) -> List[int]:
        # ���ִ������� n / k �������ֻ�� k - 1 ��
        a, b = 0, 0
        # c1, c2 �ֱ�ͳ�ƺ�ѡ�����ֵĴ���
        c1, c2 = 0, 0
        for num in nums:
            if c1 != 0 and num == a:
                c1 += 1
            elif c2 != 0 and num == b:
                c2 += 1
            elif c1 == 0:
                a, c1 = num, c1 + 1
            elif c2 == 0:
                b, c2 = num, c2 + 1
            else:
                c1, c2 = c1 - 1, c2 - 1
        # �ٽ���һ�α��������
        c1, c2 = 0, 0
        for num in nums:
            if num == a:
                c1 += 1
            elif num == b:
                c2 += 1
        ans = []
        if c1 > len(nums) // 3:
            ans.append(a)
        if c2 > len(nums) // 3:
            ans.append(b)
        return ans
