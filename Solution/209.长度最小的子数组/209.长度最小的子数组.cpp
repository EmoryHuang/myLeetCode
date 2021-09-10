/*
 * @Descroption: LeetCode 209. 长度最小的子数组
 * @Author: EmoryHuang
 * @Date: 2021-05-23 14:56:11
 * @解题思路:
 * 滑动窗口，定义i，j两个指针分别指向子数组的开头结尾
 * 遍历时，每次更新 sum += nums[j]，若sum >= target，则i向后移动
 */
 
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, len = INT_MAX;
        int i = 0, j = 0;
        while (j < n) {
            sum += nums[j];
            while (sum >= target) {
                len = min(len, j - i + 1);
                sum -= nums[i++];
            }
            j++;
        }
        return len == INT_MAX ? 0 : len;
    }
};