/*
 * @Descroption: LeetCode 27. 移除元素
 * @Author: EmoryHuang
 * @Date: 2021-03-19 19:31:36
 * @解题思路: 和前一题(删除有序数组中的重复项)的思想基本相同
 * 由于只需要输出前 len 个不重复的元素，可以把不重复的元素依次往前放
 * 设置两个指针 `i`，`j`，`i` 为慢指针，`j` 为快指针，比较 `nums[i]` 和 `val`
 * 若相等则指针 `i` 后移，进行下一次比较
 * 否则，将 `i` 位置的元素放到 `j` 位置上，然后指针 `i`,`j` 再后移
 */

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};