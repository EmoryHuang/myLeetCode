/*
 * @Descroption: LeetCode 859. 亲密字符串
 * @Author: EmoryHuang
 * @Date: 2021-06-09 19:54:00
 * @解题思路:
 * 字符串长度不相等, 直接返回false
 * 字符串相等的时候, 只要有重复的元素就返回true
 * A, B字符串有不相等的两个地方, 需要查看它们交换后是否相等即可
 */

class Solution {
   public:
    bool buddyStrings(string a, string b) {
        if (a.size() != b.size()) return false;
        if (a == b) {
            set<char> s;
            for (auto c : a) {
                if (s.count(c) != 0) return true;  // 有重复元素
                s.insert(c);
            }
            return false;
        }
        int first = -1, second = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (first == -1)
                    first = i;
                else if (second == -1)
                    second = i;
                else
                    return false;
            }
        }
        return second != -1 && a[first] == b[second] && a[second] == b[first];
    }
};