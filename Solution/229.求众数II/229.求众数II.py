'''
Descroption: LeetCode 229. 求众数 II
Author: EmoryHuang
Date: 2021-10-22 09:08:10
Method:
方法一：哈希表
使用哈希表记录元素数量

方法二：摩尔投票法
与 169. 多数元素 类似
出现次数超过 n / k 的数最多只有 k - 1 个

摩尔投票法: 每次从序列里选择两个不相同的数字删除掉（或称为“抵消”），
最后剩下一个数字或几个相同的数字，就是出现次数「可能」大于总数一半的那个
'''


class Solution:
    # 方法一：哈希表
    # def majorityElement(self, nums: List[int]) -> List[int]:
    #     n = len(nums)
    #     ans = []
    #     hash = Counter(nums)
    #     for key, val in hash.items():
    #         if val > n // 3:
    #             ans.append(key)
    #     return ans

    # 方法二：摩尔投票法
    def majorityElement(self, nums: List[int]) -> List[int]:
        # 出现次数超过 n / k 的数最多只有 k - 1 个
        a, b = 0, 0
        # c1, c2 分别统计候选数出现的次数
        c1, c2 = 0, 0
        for num in nums:
            if c1 != 0 and num == a:
                c1 += 1
            elif c2 != 0 and num == b:
                c2 += 1
            elif c1 == 0:
                a, c1 = num, c1 + 1
            elif c2 == 0:
                b, c2 = num, c2 + 1
            else:
                c1, c2 = c1 - 1, c2 - 1
        # 再进行一次遍历，检查
        c1, c2 = 0, 0
        for num in nums:
            if num == a:
                c1 += 1
            elif num == b:
                c2 += 1
        ans = []
        if c1 > len(nums) // 3:
            ans.append(a)
        if c2 > len(nums) // 3:
            ans.append(b)
        return ans
