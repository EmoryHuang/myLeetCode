'''
Descroption: LeetCode 2044. ͳ�ư�λ���ܵõ����ֵ���Ӽ���Ŀ
Author: EmoryHuang
Date: 2022-03-15 10:13:55
Method:
����һ��������ö��
������ö�٣�ʹ�� n λ�����Ƽ�¼ nums �е�ÿ�������Ƿ�ѡ��
ͬʱά����λ���ܵõ������ֵ

��������dfs
����ö��ÿ�� num �Ƿ�ѡ�񣬲���¼�ܵõ������ֵ
'''

class Solution:
    # ����һ��������ö��
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        n = len(nums)
        ans, max_num = 0, 0
        for s in range(1 << n):
            num = 0
            for i in range(n):
                if ((s >> i) & 1 == 1):
                    num |= nums[i]
            if num > max_num:
                max_num = num
                ans = 1
            elif max_num == num:
                ans += 1
        return ans

    # # ��������dfs
    # def countMaxOrSubsets(self, nums: List[int]) -> int:
    #     def dfs(idx, num):
    #         if idx == len(nums):
    #             if num > self.max_num:
    #                 self.max_num = num
    #                 self.ans = 1
    #             elif self.max_num == num:
    #                 self.ans += 1
    #             return
    #         dfs(idx + 1, num)
    #         dfs(idx + 1, num | nums[idx])

    #     self.ans, self.max_num = 0, 0
    #     dfs(0, 0)
    #     return self.ans
