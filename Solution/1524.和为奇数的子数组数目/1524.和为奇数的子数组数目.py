'''
Descroption: LeetCode 1524. 和为奇数的子数组数目
Author: EmoryHuang
Date: 2021-08-09 19:25:42
Method:
前缀和
统计当前前缀和的子前缀和奇数偶数的个数
当下标 i 的位置的前缀和是偶数时，和为奇数的子数组的数量即为奇数前缀和的数量 odd
当下标 i 的位置的前缀和是奇数时，和为奇数的子数组的数量即为偶数前缀和的数量 even
'''


class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        ans, sum = 0, 0
        odd, even = 0, 1
        for num in arr:
            sum += num
            ans += odd if sum % 2 == 0 else even
            if sum % 2 == 0:
                even += 1
            else:
                odd += 1
        return ans % 1000000007