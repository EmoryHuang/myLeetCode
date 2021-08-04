'''
Descroption: LeetCode 611. ��Ч�����εĸ���
Author: EmoryHuang
Date: 2021-08-04 14:55:15
Method:
�Ӵ�С������ߣ�Ȼ������˫ָ��Ѱ�Һ��ʵ�`j`��`k`��`[j, k - 1]`����������
'''


class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        cnt = 0
        for a in range(len(nums) - 1, 1, -1):
            b, c = 0, a - 1
            while b < c:
                # ��������������
                if nums[a] < nums[b] + nums[c]:
                    cnt += c - b
                    c -= 1
                else:
                    b += 1
        return cnt