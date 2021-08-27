'''
Descroption: LeetCode 1387. 将整数按权重排序
Author: EmoryHuang
Date: 2021-08-27 14:42:13
Method:
按照权重，原始数据进行排序
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
