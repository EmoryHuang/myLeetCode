'''
Descroption: ������ 16.01. ��������
Author: EmoryHuang
Date: 2021-07-18 14:28:21
����˼·:
��Ϊֻ����������������ʵ����ֱ�ӽ�������
���x ^ 0 = x, x ^ x = 0
'''


class Solution:
    def swapNumbers(self, numbers: List[int]) -> List[int]:
        numbers[0] = numbers[0] ^ numbers[1]
        numbers[1] = numbers[0] ^ numbers[1]
        numbers[0] = numbers[0] ^ numbers[1]
        return numbers
