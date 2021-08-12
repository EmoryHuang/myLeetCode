'''
Descroption: LeetCode 496. ��һ������Ԫ�� I
Author: EmoryHuang
Date: 2021-08-12 19:09:23
Method:
����ջ + ��ϣ��
ά��һ������ջ��ͳ�� nums2 �е�ǰ�ַ��ұ߸��������
Ȼ����� nums1 ͬ���Ƕ�Ӧλ�õıȽ�
'''


class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        hash = {}
        stack = []
        for num in nums2:
            # ά��һ������ջ
            while stack and stack[-1] < num:
                hash[stack.pop()] = num
            stack.append(num)
        return [hash.get(num, -1) for num in nums1]
