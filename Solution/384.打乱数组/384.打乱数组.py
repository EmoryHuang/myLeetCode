'''
Descroption: LeetCode 384. 打乱数组
Author: EmoryHuang
Date: 2021-11-22 18:32:45
Method:
洗牌算法
在 [i,n) 中随机抽取一个下标 j
将第 i 个元素与第 j 个元素交换
'''


class Solution:
    def __init__(self, nums: List[int]):
        self.nums = nums

    def reset(self) -> List[int]:
        return self.nums

    def shuffle(self) -> List[int]:
        ans = self.nums.copy()
        # 在 [i,n) 中随机抽取一个下标 j
        # 将第 i 个元素与第 j 个元素交换
        for i in range(len(ans)):
            j = random.randint(0, i)
            ans[i], ans[j] = ans[j], ans[i]
        return ans

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()