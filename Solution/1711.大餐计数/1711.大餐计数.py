'''
Descroption: LeetCode 1711. 大餐计数
Author: EmoryHuang
Date: 2021-07-07 19:14:19
解题思路:
用哈希表记录加数以及它出现的次数
遍历所有可能的2的幂，利用遍历的2的幂减去当前数，得出对应补数
'''


class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        ans = 0
        hash = defaultdict(int)
        for num in deliciousness:
            for i in range(22):
                if (1 << i) - num in hash:
                    cnt = hash[(1 << i) - num]
                    ans += cnt
                    ans %= 1000000007
            hash[num] += 1
        return ans
