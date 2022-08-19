/*
 * @Descroption: LeetCode 1224. 最大相等频率
 * @Author: EmoryHuang
 * @Date: 2022-08-18 14:24:08
 * @Method:
 * 计数模拟
 * cnt 和 freq 分别记录数字出现的次数，以及次数出现的数目
 * 依次遍历数组并更新，出现如下三种情况：
 * - max_freq == 1
 * - max_freq有1个数字，max_freq - 1有n - 1个数字
 * - max_freq有n - 1个数字，max_freq - 1有1个数字
 */

class Solution {
    public int maxEqualFreq(int[] nums) {
        // cnt 和 freq 分别记录数字出现的次数，以及次数出现的数目
        int[] cnt = new int[100001];
        int[] freq = new int[100001];
        int ans = 0, max_freq = 0;
        for (int i = 0; i < nums.length; i++) {
            // 如果当前数字出现，那么次数需要修改
            if (cnt[nums[i]] > 0)
                freq[cnt[nums[i]]]--;
            cnt[nums[i]]++;
            max_freq = Math.max(max_freq, cnt[nums[i]]);
            freq[cnt[nums[i]]]++;
            if (max_freq == 1 ||
                    freq[max_freq] * max_freq + freq[max_freq - 1] * (max_freq - 1) == i + 1
                            && freq[max_freq] == 1
                    ||
                    freq[max_freq] * max_freq + 1 == i + 1 && freq[1] == 1) {
                ans = Math.max(ans, i + 1);
            }
        }
        return ans;
    }
}