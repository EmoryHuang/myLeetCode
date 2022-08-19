/*
 * @Descroption: LeetCode 744. 寻找比目标字母大的最小字母
 * @Author: EmoryHuang
 * @Date: 2021-05-30 10:50:00
 * @解题思路:
 * 遍历数组，返回第一个大于 target 的元素
 * 若 target 大于 letters 中的所有元素，则返回第一个元素
 *
 * 方法二：二分寻找
 */

class Solution {
   public:
    // 方法一：直接遍历
    // char nextGreatestLetter(vector<char>& letters, char target) {
    //     for (auto letter : letters) {
    //         if (letter > target) return letter;
    //     }
    //     return letters[0];  // 若target大于letters中的所有元素，则返回第一个元素
    // }

    // 方法二：二分
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (letters[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        // 若target大于letters中的所有元素，则返回第一个元素
        return letters[l % n];
    }
};