/*
* @Descroption: LeetCode 1470. 重新排列数组
* @Author: EmoryHuang
* @Date: 2022-08-29 09:42:09
* @Method:
* 一次遍历分配元素
*/

class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] ans = new int[2 * n];
        for (int i = 0; i < n; i++) {
            ans[2 * i] = nums[i];
            ans[2 * i + 1] = nums[n + i];
        }
        return ans;
    }
}