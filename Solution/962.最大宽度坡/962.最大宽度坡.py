'''
Descroption: LeetCode 962. �������
Author: EmoryHuang
Date: 2021-07-10 14:52:13
����˼·:
��������������飬ջ�д�ŵݼ�Ԫ��
�Ӻ���ǰ����, ����ÿ������Ԫ�ش���ջ���ľͿ��Լ����ȣ�Ȼ��ջ������
'''


class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        st = []
        for i in range(len(nums)):
            # st �д�ŵݼ�Ԫ��
            if not st or nums[st[-1]] > nums[i]:
                st.append(i)
        ans = 0
        # �Ӻ���ǰ����
        for i in range(len(nums) - 1, -1, -1):
            while st and nums[i] >= nums[st[-1]]:
                ans = max(ans, i - st[-1])
                st = st[:-1]
        return ans
