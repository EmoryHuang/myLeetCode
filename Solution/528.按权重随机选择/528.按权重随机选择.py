'''
Descroption: LeetCode 528. 按权重随机选择
Author: EmoryHuang
Date: 2021-08-30 22:03:43
Method:
前缀和 + 二分
每个元素代表一个权重，数字越大的元素，它的权重越大
可以使用前缀和数组来作为权重分布序列
随机数从前缀和数组中产生
通过这个随机数，再定位到数组的下标即可
'''


class Solution:
    def __init__(self, w: List[int]):
        n = len(w)
        self.pre = [0] * n
        self.pre[0] = w[0]
        # 计算前缀和
        for i in range(n):
            self.pre[i] = self.pre[i - 1] + w[i]

    def pickIndex(self) -> int:
        seed = random.randint(1, self.pre[-1])
        pre = self.pre
        n = len(pre)
        # 二分寻找第一个满足 seed <= pre[i] 的元素 i
        l, r = 0, n - 1
        while l < r:
            mid = l + r >> 1
            if pre[mid] >= seed:
                r = mid
            else:
                l = mid + 1
        return l


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()