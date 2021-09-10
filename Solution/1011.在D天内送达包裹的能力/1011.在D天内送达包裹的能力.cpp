/*
 * @Descroption: LeetCode 1011. 在 D 天内送达包裹的能力
 * @Author: EmoryHuang
 * @Date: 2021-04-26 13:20:36
 * @解题思路:
 * 使用二分查找，左边界为数组 `weights` 中元素的最大值，右边界为数组 `weights` 中元素的和
 * 将连续的包裹都安排在同一天进行运送。当这批包裹的重量大于运载能力x时，就需要将最后一个包裹拿出来，安排在新的一天，并继续往下遍历。
 * 当遍历完整个数组后，就得到了最少需要运送的天数，最后将「最少需要运送的天数」与 D 进行比较
 */

class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int D) {
        int right = 0, left = 0;
        for (int w : weights) {
            right += w;           // right为weights各元素之和
            left = max(left, w);  // left为weights中的最大值
        }
        while (left < right) {
            int tmp = 0, day = 1;                 // tmp为每天运货量
            int mid = left + (right - left) / 2;  // mid为运货能力
            for (int w : weights) {
                tmp += w;
                if (tmp > mid) {
                    day++;  // 下一天运送
                    tmp = w;
                }
            }
            if (day <= D)  // 不足D天
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};