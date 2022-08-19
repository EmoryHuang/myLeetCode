'''
Descroption: LeetCode 881. 救生艇
Author: EmoryHuang
Date: 2021-08-26 15:53:48
Method:
双指针 + 排序
首先对数组进行排序，维护两个指针l和r，分别指向头尾
若 people[l] + people[r] <= limit 说明能够载2人，指针分别向右，向左更新
否则，people[r] 需要单独安排船，右指针向左移动
'''


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        ans, l, r = 0, 0, len(people) - 1
        while l <= r:
            if people[l] + people[r] <= limit:
                l += 1
            r -= 1
            ans += 1
        return ans
