'''
Descroption: LeetCode 1694. 重新格式化电话号码
Author: EmoryHuang
Date: 2022-10-01 14:15:16
Method:
首先取数字，接着根据题意对数字进行划分
'''


class Solution:
    def reformatNumber(self, number: str) -> str:
        nums = [i for i in number if i.isdigit()]
        ans = []
        n, idx = len(nums), 0
        while n:
            if n > 4:
                ans.append(''.join(nums[idx:idx + 3]))
                idx += 3
                n -= 3
            else:
                if n == 4:
                    ans.append(''.join(nums[idx:idx + 2]))
                    ans.append(''.join(nums[idx + 2:idx + 4]))
                else:
                    ans.append(''.join(nums[idx:idx + n]))
                break
        return '-'.join(ans)
