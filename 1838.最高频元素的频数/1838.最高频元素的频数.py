'''
Descroption: LeetCode 1838. ���ƵԪ�ص�Ƶ��
Author: EmoryHuang
Date: 2021-07-19 14:28:15
����˼·:
����һ������ + ��������
�жϵ�ǰ���������Ƿ���������
������������ + �������� + ����
���ȣ�ͨ�����ַ��жϵ�ǰѡ��Ƶ���Ƿ����
������˵��ͨ���������ڽ����жϣ�����Ƶ���̶���������ǿ����жϣ���ǰ�����ڵ�Ԫ���Ƿ���������
Ŀ�����ּ�Ϊ��ǰ�����Ҷ˵��Ӧ�����֣�ͨ���ж�Ŀ������ͼ����жϵ�ǰ�����Ƿ���������
'''


class Solution:
    # ����һ������ + ��������
    # def maxFrequency(self, nums: List[int], k: int) -> int:
    #     n = len(nums)
    #     nums.sort()
    #     l = r = diff = 0
    #     ans = 1
    #     for r in range(1, n):  # �������������Ҷ˵�
    #         diff += (r - l) * (nums[r] - nums[r - 1])
    #         if diff > k:
    #             diff -= nums[r] - nums[l]
    #             l += 1
    #         ans = max(ans, r - l + 1)
    #     return ans

    # ������������ + �������� + ����
    def maxFrequency(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        pre = [0] * (n + 1)
        for i in range(1, n + 1):
            pre[i] = pre[i - 1] + nums[i - 1]

        # �жϵ�ǰƵ���Ƿ����
        def check(fre: int) -> bool:
            # ��������������˵�
            for i in range(n + 1 - fre):
                j = i + fre - 1  # ���������Ҷ˵�
                diff = fre * nums[j] - (pre[j + 1] - pre[i])
                if diff <= k:
                    return True
            return False

        l, r = 0, n
        while l < r:
            mid = l + r + 1 >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
