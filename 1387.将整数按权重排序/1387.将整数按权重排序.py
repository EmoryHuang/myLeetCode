'''
Descroption: LeetCode 1387. ��������Ȩ������
Author: EmoryHuang
Date: 2021-08-27 14:42:13
Method:
����Ȩ�أ�ԭʼ���ݽ�������
'''


class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        def to_one(num: int) -> int:
            cnt = 0
            while num != 1:
                if num % 2 == 0:
                    num /= 2
                else:
                    num = 3 * num + 1
                cnt += 1
            return cnt

        nums = list(range(lo, hi + 1))
        nums.sort(key=lambda x: (to_one(x), x))
        return nums[k - 1]
