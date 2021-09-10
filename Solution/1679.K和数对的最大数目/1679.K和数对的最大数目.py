'''
Descroption: LeetCode 1679. K �����Ե������Ŀ
Author: EmoryHuang
Date: 2021-07-20 20:51:09
����˼·:
�����������ڵ�ÿһ����������¼λ�������ڵ�Ԫ�ص�����
'''


class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        cnt = 0
        hash = defaultdict(int)
        for num in nums:
            # ���û�ж�Ӧ�ļ�������¼ num
            if hash[k - num] == 0:
                hash[num] += 1
            # ����ж�Ӧ�ļ�������¼ k - num
            else:
                cnt += 1
                hash[k - num] -= 1
        return cnt
