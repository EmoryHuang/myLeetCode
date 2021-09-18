'''
Descroption: LeetCode 728. �Գ���
Author: EmoryHuang
Date: 2021-09-18 20:20:52
Method:
������Χ�ڵ�ÿ�������ж��ǲ����Գ���
'''


class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        ans = []
        for num in range(left, right + 1):
            if num % 10 == 0: continue
            tmp = num
            while tmp:
                if tmp % 10 == 0 or num % (tmp % 10):
                    break
                tmp //= 10
            if tmp == 0:
                ans.append(num)
        return ans