'''
Descroption: LeetCode 1296. ��������Ϊ�������ֵļ���
Author: EmoryHuang
Date: 2021-07-15 19:46:25
����˼·:
�ù�ϣ���¼����Ԫ�ص�����
��������Ԫ�ؽ��б���������ÿ��Ԫ�� num
�� num + i �ĸ���Ϊ0���򷵻� false
'''


class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        if n % k != 0:
            return False
        nums.sort()
        mp = defaultdict(int)
        for num in nums:
            mp[num] += 1
        for num in nums:
            if mp[num] == 0:
                continue
            for i in range(k):
                if num + i not in mp:
                    return False
                mp[num + i] -= 1
        return True
