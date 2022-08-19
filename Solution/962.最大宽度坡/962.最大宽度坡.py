'''
Descroption: LeetCode 962. 最大宽度坡
Author: EmoryHuang
Date: 2021-07-10 14:52:13
解题思路:
首先正向遍历数组，栈中存放递减元素
从后往前遍历, 这样每次遇到元素大于栈顶的就可以计算宽度，然后将栈顶弹出
'''


class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        st = []
        for i in range(len(nums)):
            # st 中存放递减元素
            if not st or nums[st[-1]] > nums[i]:
                st.append(i)
        ans = 0
        # 从后往前遍历
        for i in range(len(nums) - 1, -1, -1):
            while st and nums[i] >= nums[st[-1]]:
                ans = max(ans, i - st[-1])
                st = st[:-1]
        return ans
