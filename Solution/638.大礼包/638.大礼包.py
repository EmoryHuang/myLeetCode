'''
Descroption: LeetCode 638. 大礼包
Author: EmoryHuang
Date: 2021-10-24 18:52:44
Method:
dfs 记忆化
使用 cache 记录出现的子问题
首先考虑在当前需求下不购买大礼包的花费，然后遍历每个大礼包，判断是否符合需求
对于符合要求的大礼包，更新需求
然后递归的求解不同需求下的最小花费
'''


class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]],
                       needs: List[int]) -> int:
        @lru_cache(None)
        def dfs(cur) -> int:
            ans = 0
            # 不购买大礼包
            for i in range(len(cur)):
                ans += cur[i] * price[i]
            # 遍历每个礼包
            for bag in special:
                nxt = tuple(x - y for x, y in zip(cur, bag))
                if all(x >= 0 for x in nxt):
                    ans = min(ans, dfs(nxt) + bag[-1])
            return ans

        return dfs(tuple(needs))