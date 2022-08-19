'''
Descroption: LeetCode 1833. 雪糕的最大数量
Author: EmoryHuang
Date: 2021-07-02 12:54:00
解题思路:
贪心思想，排序后从前往后选择
'''


class Solution:
    # sort
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        ans = 0
        for cost in costs:
            coins -= cost
            if coins < 0:
                return ans
            ans += 1
        if coins >= 0:
            return ans
        return 0

    # 快排
    # def maxIceCream(self, costs: List[int], coins: int) -> int:

    #     def quicksort(l: int, r: int) -> None:
    #         if l >= r:
    #             return
    #         pivot = costs[l]
    #         low, high = l, r
    #         while low < high:
    #             while low < high and costs[high] >= pivot:
    #                 high -= 1
    #             while low < high and costs[low] <= pivot:
    #                 low += 1
    #             if low < high:
    #                 costs[low], costs[high] = costs[high], costs[low]
    #         costs[low], costs[l] = costs[l], costs[low]
    #         quicksort(l, low - 1)
    #         quicksort(low + 1, r)

    #     quicksort(0, len(costs) - 1)
    #     ans = 0
    #     for cost in costs:
    #         coins -= cost
    #         if coins < 0:
    #             return ans
    #         ans += 1
    #     if coins >= 0:
    #         return ans
    #     return 0
