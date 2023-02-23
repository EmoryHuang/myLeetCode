/*
 * @Descroption: LeetCode 2341. 数组能形成多少数对
 * @Author: EmoryHuang
 * @Date: 2023-02-16 09:20:55
 * @Method:
 * 简单题，哈希表记录数字出现次数
 */

class Solution {
    public int[] numberOfPairs(int[] nums) {
        Map<Integer, Boolean> cnt = new HashMap<>();
        int ans = 0;
        for (int num : nums) {
            cnt.put(num, !cnt.getOrDefault(num, false));
            if (!cnt.get(num)) {
                ans++;
            }
        }
        return new int[] { ans, nums.length - ans * 2 };
    }
}