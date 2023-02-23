'''
Descroption: LeetCode 1805. 字符串中不同整数的数目
Author: EmoryHuang
Date: 2021-07-14 20:45:41
解题思路:
遍历数组，若遇到数字，则记录
将不同的数字放入数组
'''


class Solution:
    # 方法一：暴力
    # def numDifferentIntegers(self, word: str) -> int:
    #     nums = []
    #     num = ''
    #     for ch in word:
    #         if ch.isdigit():
    #             num += ch
    #         else:
    #             if num != '' and int(num) not in nums:
    #                 nums.append(int(num))
    #             num = ''
    #     if num != '' and int(num) not in nums:
    #         nums.append(num)
    #     return len(nums)

    # 方法二：正则
    def numDifferentIntegers(self, word: str) -> int:
        return len(set(int(each) for each in re.findall(r"([0-9]+)", word)))