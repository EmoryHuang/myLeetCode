/*
 * @Descroption: LeetCode 1781. 所有子字符串美丽值之和
 * @Author: EmoryHuang
 * @Date: 2022-12-12 09:37:07
 * @Method:
 * 遍历所有子字符串，使用哈希表记录字符的出现次数并计算美丽值
 */

class Solution {
    public int beautySum(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int[] cnt = new int[26];
            int mx = 0;
            for (int j = i; j < s.length(); j++) {
                cnt[s.charAt(j) - 'a']++;
                mx = Math.max(mx, cnt[s.charAt(j) - 'a']);
                int min_freq = s.length();
                for (int k = 0; k < 26; k++) {
                    if (cnt[k] > 0) {
                        min_freq = Math.min(min_freq, cnt[k]);
                    }
                }
                ans += mx - min_freq;
            }
        }
        return ans;
    }
}