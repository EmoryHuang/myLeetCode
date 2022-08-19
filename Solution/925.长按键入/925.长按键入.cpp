/*
 * @Descroption: LeetCode 925. 长按键入
 * @Author: EmoryHuang
 * @Date: 2021-04-27 15:30:36
 * @解题思路:
 * 设置双指针 `i`，`j`，分别指向 `name` 和 `typed` 比较字符是否匹配，若有重复则 `j++`
 */

class Solution {
   public:
    bool isLongPressedName(string name, string typed) {
        int m = name.size();
        int n = typed.size();
        if (m > n) return false;
        int i = 0, j = 0;
        while (j < n) {
            if (i < m && name[i] == typed[j]) {  // 如果把i<m放在while，则不能处理type还要剩余的情况
                i++;
                j++;
            } else if (j > 0 && typed[j - 1] == typed[j])  // 重复情况
                j++;
            else
                return false;
        }
        return i == m;  //全有
    }
};