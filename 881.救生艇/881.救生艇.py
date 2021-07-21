'''
Descroption: LeetCode 881. 救生艇
Author: EmoryHuang
Date: 2021-07-21 20:16:19
解题思路:
双指针 + 贪心
如果最左边和最右边的人能上船，那么这两个人就走
如果最左边和最右边的人不能上船，最右边的人单独走
'''


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        cnt = 0
        l, r = 0, len(people) - 1
        while l <= r:
            if people[l] + people[r] <= limit:
                # 如果最左边和最右边的人能上船
                l += 1
                r -= 1
                cnt += 1
            else:
                # 如果最左边和最右边的人不能上船，最右边的人单独走
                r -= 1
                cnt += 1
        return cnt
