/*
 * @Descroption: LeetCode 904. 水果成篮
 * @Author: EmoryHuang
 * @Date: 2022-10-17 09:22:02
 * @Method:
 * 滑动窗口
 * 将题目的问题转化一下：求仅包含两个元素的最长子序列
 * 使用哈希表记录篮子中的元素
 */


class Solution {
    public int totalFruit(int[] fruits) {
        int ans = 0;
        int l = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int r = 0; r < fruits.length; r++) {
            cnt.put(fruits[r], cnt.getOrDefault(fruits[r], 0) + 1);
            if (cnt.size() > 2) {
                cnt.put(fruits[l], cnt.get(fruits[l]) - 1);
                if (cnt.get(fruits[l]) == 0)
                    cnt.remove(fruits[l]);
                l++;
            }
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}