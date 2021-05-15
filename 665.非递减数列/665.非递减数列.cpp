/*
 * @Descroption: LeetCode 665. 非递减数列
 * @Author: EmoryHuang
 * @Date: 2021-03-19 15:19:36
 * @解题思路:
 * 如果出现 `nums[i] > nums[i+1]` 的情况，改变一个数，面临两种选择，
 * 一是把 `nums[i]` 变大，二是把 `nums[i+1]` 变小
 * 但同时还需要比较 `nums[i-1]` 与 `nums[i+1]` 的值
 * 例如 `... 1 4 3 ...` 只能选择把 4 变小， `... 3 4 1 ...` 只能选择把 1 变大(这里`nums[i]=4`)
 */

class Solution {
   public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size(), count = 0;
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] > nums[i + 1]) {                   //若存在逆序
                if (i == 0 || nums[i + 1] >= nums[i - 1])  //考虑开头情况，以及第i个字符的前后大小
                    nums[i] = nums[i + 1];  // nums[i]变大
                else
                    nums[i + 1] = nums[i];  // nums[i-1]变小
                count++;
            }
        }
        return count < 2;
    }
};