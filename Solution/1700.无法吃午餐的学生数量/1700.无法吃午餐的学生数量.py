'''
Descroption: LeetCode 1700. 无法吃午餐的学生数量
Author: EmoryHuang
Date: 2022-10-19 09:12:30
Method:
哈希表记录喜欢吃每种三明治的学生数
按顺序遍历三明治数组，把对应的三明治分给喜欢的学生
'''


class Solution:

    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        cnt = Counter(students)
        for s in sandwiches:
            if cnt[s]:
                cnt[s] -= 1
            else:
                break
        return cnt[0] + cnt[1]
