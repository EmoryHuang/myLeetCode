'''
Descroption: LeetCode 904. 水果成篮
Author: EmoryHuang
Date: 2021-11-04 20:26:40
Method:
滑动窗口
将题目的问题转化一下：求仅包含两个元素的最长子序列
使用哈希表记录篮子中的元素
'''


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        ans, l = 0, 0
        cnt = Counter()
        for r, x in enumerate(fruits):
            cnt[x] += 1
            if len(cnt) >= 3:
                # 滑动窗口左移
                cnt[fruits[l]] -= 1
                # 如果左端点的值变为 0 则删除
                if cnt[fruits[l]] == 0:
                    del cnt[fruits[l]]
                l += 1
            # 更新最大长度
            ans = max(ans, r - l + 1)
        return ans
