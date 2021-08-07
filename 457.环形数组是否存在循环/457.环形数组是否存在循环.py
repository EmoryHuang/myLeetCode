'''
Descroption: LeetCode 457. 环形数组是否存在循环
Author: EmoryHuang
Date: 2021-08-07 14:17:33
Method:
模拟
从每个下标 i 进行出发检查，如果以某个下标 i 为出发点发现了「循环」，返回 True，否则返回 False
'''


class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)

        def check(start: int) -> bool:
            cur = start
            cnt = 1  # 记录过程中扫描过的下标数量
            while True:
                if cnt > n: return False
                next = ((cur + nums[cur]) % n + n) % n
                # 不全是正数或者负数
                if nums[start] > 0 and nums[next] < 0:
                    return False
                if nums[start] < 0 and nums[next] > 0:
                    return False
                if start == next:
                    # 找到了与起点相同的下标
                    return cnt > 1
                cur = next
                cnt += 1

        for i in range(n):
            if check(i):
                return True
        return False