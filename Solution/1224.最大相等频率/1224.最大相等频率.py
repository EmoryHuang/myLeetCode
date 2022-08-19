'''
Descroption: LeetCode 1224. 最大相等频率
Author: EmoryHuang
Date: 2022-08-18 14:18:44
Method:
计数模拟
cnt 和 freq 分别记录数字出现的次数，以及次数出现的数目
依次遍历数组并更新，出现如下三种情况：
- max_freq == 1
- max_freq有1个数字，max_freq - 1有n - 1个数字
- max_freq有n - 1个数字，max_freq - 1有1个数字
'''


class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        # cnt 和 freq 分别记录数字出现的次数，以及次数出现的数目
        cnt, freq = Counter(), Counter()
        ans = max_freq = 0
        for i, num in enumerate(nums):
            # 如果当前数字出现，那么次数需要修改
            if cnt[num]:
                freq[cnt[num]] -= 1
            cnt[num] += 1
            max_freq = max(max_freq, cnt[num])
            freq[cnt[num]] += 1
            if max_freq == 1 or \
               freq[max_freq] * max_freq + freq[max_freq - 1] * (max_freq - 1) == i + 1 and freq[max_freq] == 1 or \
               freq[max_freq] * max_freq + 1 == i + 1 and freq[1] == 1:
                ans = max(ans, i + 1)
        return ans
