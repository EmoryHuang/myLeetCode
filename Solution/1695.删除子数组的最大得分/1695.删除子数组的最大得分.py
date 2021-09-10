'''
Descroption: LeetCode 1695. ɾ������������÷�
Author: EmoryHuang
Date: 2021-08-10 14:52:18
Method:
��������
�������飬����ǰԪ��δ���룬����봰�ڣ�
���������������ظ�Ԫ�أ����ƶ��󴰿ڣ�ɾ���ظ�Ԫ��֮ǰ������Ԫ��
'''


class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, 0
        ans, sum, hash = 0, 0, []
        while r < n:
            # ����ǰԪ��δ����
            if nums[r] not in hash:
                hash.append(nums[r])
                sum += nums[r]
                ans = max(ans, sum)
            else:
                # ɾ���ظ�Ԫ��֮ǰ������Ԫ��
                while nums[l] != nums[r]:
                    sum -= nums[l]
                    hash.remove(nums[l])
                    l += 1
                l += 1
            r += 1
        return ans
