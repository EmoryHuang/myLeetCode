/*
 * @Descroption: LeetCode 75. 颜色分类
 * @Author: EmoryHuang
 * @Date: 2021-05-12 16:17:36
 * @解题思路:
 * 邪道做法 sort()
 *
 * 设置双指针，分别指向 0，1
 * 遍历数组，如果为 1，那么交换位置，并且 p1 后移；
 * 如果为 0，那么交换位置，并且还要判断 p0 和 p1 的位置再次交换，p0,p1 后移
 */

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0;  // 分别指向0，1
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                p1++;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) swap(nums[i], nums[p1]);
                p0++;
                p1++;  // 0在1前，因此p1也要后移
            }
        }
    }
};