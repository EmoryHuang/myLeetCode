'''
Descroption: LeetCode 1346. ������������������Ƿ����
Author: EmoryHuang
Date: 2021-07-25 14:37:15
Method:
���⣬ʹ�ù�ϣ��洢Ԫ��
����0��Ҫ���⿼��
'''


class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        counter = collections.Counter(arr)
        for num in arr:
            if num and counter[num * 2] >= 1:
                return True
            # ����0��Ҫ���⿼��
            if not num and counter[num * 2] >= 2:
                return True
        return False