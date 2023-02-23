/*
 * @Descroption: LeetCode 1769. 移动所有球到每个盒子所需的最小操作数
 * @Author: EmoryHuang
 * @Date: 2022-12-02 09:18:23
 * @Method:
 * 遍历数组，依次处理每个盒子的移动情况
 */

class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            int step = 0;
            for (int j = 0; j < n; j++) {
                if (boxes.charAt(j) == '1') {
                    step += Math.abs(i - j);
                }
            }
            ans[i] = step;
        }
        return ans;
    }
}