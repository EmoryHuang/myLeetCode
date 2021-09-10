'''
Descroption: ��ָ Offer 11. ��ת�������С����
Author: EmoryHuang
Date: 2021-06-29 20:12:00
����˼·:
���ַ�
����м��Ԫ�ر��ұߵ�Ԫ��С����ô���㣬�� r = mid����Ϊ mid ��������СԪ��
����м��Ԫ�ر��ұߵ�Ԫ�ش���ô�� l = mid + 1����Ϊ mid ����������СԪ��
����м��Ԫ�ص����ұߵ�Ԫ�أ���ô�� r--����С��Χ
'''


class Solution:
    def minArray(self, numbers: List[int]) -> int:
        l, r = 0, len(numbers) - 1
        while l < r:
            mid = l + (r - l) // 2
            if numbers[mid] < numbers[r]:
                r = mid
            elif numbers[mid] > numbers[r]:
                l = mid + 1
            else:
                r -= 1
        return numbers[l]
