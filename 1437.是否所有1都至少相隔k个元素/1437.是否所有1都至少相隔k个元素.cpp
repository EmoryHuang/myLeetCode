/*
 * @Descroption: LeetCode 1437. 是否所有 1 都至少相隔 k 个元素
 * @Author: EmoryHuang
 * @Date: 2021-06-05 16:04:00
 * @解题思路:
 * 遍历数组，记录相邻两个 1 之间的距离，若小于 k 则返回 false
 */

class Solution {
   public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pre = -1;  // 前一个1的位置
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (pre != -1 && (i - pre - 1) < k) return false;
                pre = i;
            }
        }
        return true;
    }
};