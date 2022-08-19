/*
 * @Descroption: LeetCode 167. 两数之和 II - 输入有序数组
 * @Author: EmoryHuang
 * @Date: 2021-04-20 16:10:36
 * @解题思路: 设置左右两个指针，判断大小进行移动，若等于目标值则返回下标
 */

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target)
                return {left + 1, right + 1};
            else if (numbers[left] + numbers[right] > target)
                right--;
            else
                left++;
        }
        return {};
    }
};