/*
 * @Descroption: LeetCode 796. 旋转字符串
 * @Author: EmoryHuang
 * @Date: 2021-06-26 14:18:00
 * @解题思路:
 * 简单题，在 s + s 中判断是否存在子串 goal
 */

class Solution {
   public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != -1;
    }
};