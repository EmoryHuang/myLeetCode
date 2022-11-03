/*
 * @Descroption: LeetCode 777. 在LR字符串中交换相邻字符
 * @Author: EmoryHuang
 * @Date: 2022-10-02 10:47:15
 * @Method:
 * 双指针
 * 比较字符串，X可以忽略，理解题意为
 * L 只能左移且不能越过 R, R 只能右移且不能越过 L
 * 即可比较 L, R 的相对位置
 */

class Solution {
    public boolean canTransform(String start, String end) {
        int n = start.length();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start.charAt(i) == 'X')
                i++;
            while (j < n && end.charAt(j) == 'X')
                j++;
            if (i >= n && j >= n)
                return true;
            if (i >= n || j >= n || start.charAt(i) != end.charAt(j))
                return false;
            if (start.charAt(i) == 'L' && i < j)
                return false;
            if (start.charAt(i) == 'R' && i > j)
                return false;
            i++;
            j++;
        }
    }
}