'''
Descroption: LeetCode 1417. 重新格式化字符串
Author: EmoryHuang
Date: 2022-08-11 09:10:31
Method:
判断数字和字母的数量差不超过 1
之后对字符串进行重排
'''


class Solution:
    def reformat(self, s: str) -> str:
        nums = [c for c in s if c.isdigit()]
        chars = [c for c in s if c.isalpha()]
        if abs(len(nums) - len(chars)) > 1:
            return ""
        ans = [None] * len(s)
        ans[1::2], ans[::2] = sorted([nums, chars], key=len)
        return "".join(ans)