/*
 * @Descroption: 面试题 01.05. 一次编辑
 * @Author: EmoryHuang
 * @Date: 2022-05-12 09:11:20
 * @Method:
 * 依次比较两个字符串中元素
 * 若第 i 个位置的元素不相同，则判断以下情况
 * first[i + 1:] == second[i + 1:] or first[i:] == second[i + 1:] or first[i + 1:] == second[i:]
 */

class Solution {
   public:
    bool oneEditAway(string first, string second) {
        int n = first.size(), m = second.size();
        if (abs(n - m) > 1) return false;
        for (int i = 0; i < min(n, m); i++) {
            if (first[i] != second[i]) {
                return first.substr(i + 1) == second.substr(i + 1) || first.substr(i) == second.substr(i + 1) ||
                       first.substr(i + 1) == second.substr(i);
            }
        }
        return abs(n - m) <= 1;
    }
};