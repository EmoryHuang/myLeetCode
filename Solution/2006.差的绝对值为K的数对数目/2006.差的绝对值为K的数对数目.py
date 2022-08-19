'''
Descroption: LeetCode 2006. ��ľ���ֵΪ K ��������Ŀ
Author: EmoryHuang
Date: 2021-10-08 19:19:55
Method:
��ϣ���¼֮ǰ�����ݸ���
'''


class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        hash = [0] * 101
        ans = 0
        for num in nums:
            if num - k >= 0:
                ans += hash[num - k]
            if num + k <= 100:
                ans += hash[num + k]
            hash[num] += 1
        return ans