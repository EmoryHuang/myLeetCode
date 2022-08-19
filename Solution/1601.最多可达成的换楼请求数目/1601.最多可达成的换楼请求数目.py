'''
Descroption: LeetCode 1601. 最多可达成的换楼请求数目
Author: EmoryHuang
Date: 2022-02-28 08:53:14
Method:
二进制枚举
使用二进制位记录选择换楼情况，遍历所有换楼请求
统计二进制数中 1 的个数，并判断当前 state 是否可以满足换楼请求
'''


class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        # 判断当前数是否可以满足换楼请求
        def check(state):
            cnt = [0] * 20
            for i, (x, y) in enumerate(requests):
                if (state >> i) & 1 == 1:
                    cnt[x] += 1
                    cnt[y] -= 1
            return all(x == 0 for x in cnt)

        ans = 0
        # 遍历所有换楼请求
        for state in range(1 << len(requests)):
            # 统计二进制数中 1 的个数
            cnt = state.bit_count()
            if cnt <= ans:
                continue
            if check(state):
                ans = max(ans, cnt)
        return ans
