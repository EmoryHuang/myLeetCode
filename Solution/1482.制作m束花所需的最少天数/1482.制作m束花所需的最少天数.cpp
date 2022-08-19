/*
 * @Descroption: LeetCode 1482. 制作 m 束花所需的最少天数
 * @Author: EmoryHuang
 * @Date: 2021-05-09 14:58:36
 * @解题思路:
 * 建立一个辅助函数 `makeBloom`，判断在第 `i` 天能不能制作出 `m` 朵花束，
 * 之后通过二分的方法，寻找最小的 `i` 值
 * 对于 `makeBloom` 来说，维护两个值，一个是花的数量 `bloom`，另一个是花束的数量 `num`，
 * 遍历 `bloomDay`，如果第 `i` 朵花开，那么记录，直到制成花束 `bloom` 清零；
 * 如果第 `i` 朵花没开，那么 `bloom` 清零
 */

class Solution {
   public:
    bool makeBloom(vector<int>& bloomDay, int day, int m, int k) {
        int bloom = 0;  // 花的数量
        int num = 0;    // 花束的数量
        for (int i = 0; i < bloomDay.size() && num < m; i++) {
            if (bloomDay[i] <= day) {
                bloom++;  // 花开
                if (bloom == k) {
                    num++;
                    bloom = 0;
                }
            } else  // 不是连续的花
                bloom = 0;
        }
        return num >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n) return -1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        while (low < high) {
            int day = low + (high - low) / 2;
            if (makeBloom(bloomDay, day, m, k))  //如果 day 天能够做出 m 朵花
                high = day;                      //继续查找更小的值
            else
                low = day + 1;
        }
        return low;
    }
};