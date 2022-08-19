'''
Descroption: LeetCode 860. 柠檬水找零
Author: EmoryHuang
Date: 2021-06-15 16:34:00
解题思路:
贪心思想，记录当前5美元和10美元的个数
然后按顺序进行分类讨论
'''


class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        if bills[0] != 5:
            return False
        five, ten = 0, 0
        for bill in bills:
            if bill == 5:
                five += 1
            elif bill == 10:
                if five == 0:
                    return False
                ten += 1
                five -= 1
            else:
                if five > 0 and ten > 0:
                    five -= 1
                    ten -= 1
                elif five >= 3:
                    five -= 3
                else:
                    return False
        return True
