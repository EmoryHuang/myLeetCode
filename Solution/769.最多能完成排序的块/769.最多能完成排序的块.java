/*
 * @Descroption: LeetCode 769. 最多能完成排序的块
 * @Author: EmoryHuang
 * @Date: 2022-10-13 09:09:30
 * @Method:
 * 贪心
 * 由于按升序排序后，数字与其下标相同
 * 那么可以遍历数组并维护当前最大值，最大值与当前下标相同时，则说明找到了正确位置
 */

class Solution {
    public int maxChunksToSorted(int[] arr) {
        int ans = 0, max_num = -1;
        for (int i = 0; i < arr.length; i++) {
            max_num = Math.max(max_num, arr[i]);
            ans += max_num == i ? 1 : 0;
        }
        return ans;
    }
}