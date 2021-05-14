/*
 * @Descroption: LeetCode 26. 删除有序数组中的重复项
 * @Author: EmoryHuang
 * @Date: 2021-03-19 19:31:36
 * @解题思路: 由于只需要输出前 len 个不重复的元素，可以把不重复的元素依次往前放
 * 设置两个指针 `i`，`j`，`i` 为慢指针，`j` 为快指针，比较 `nums[i]` 和 `nums[j]`
 * 若相等则指针 `i` 后移，进行下一次比较
 * 否则，指针 `j` 后移，将 `i` 位置的元素放到 `j` 位置上，然后指针 `i` 再后移
 */

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int len = 0;  //当前长度
        for (int i = 1; i < nums.size(); i++) {
            if (nums[len] != nums[i]) {
                nums[++len] = nums[i];  //将不相等的字符放到前面
            }
        }
        return ++len;
    }
};