'''
Descroption: LeetCode 1299. ��ÿ��Ԫ���滻Ϊ�Ҳ����Ԫ��
Author: EmoryHuang
Date: 2021-07-23 20:07:07
����˼·:
�Ӻ���ǰ�������飬ά�����ֵ
'''


class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        amax = -1
        for i in range(len(arr) - 1, -1, -1):
            amax, arr[i] = max(amax, arr[i]), amax
        return arr
