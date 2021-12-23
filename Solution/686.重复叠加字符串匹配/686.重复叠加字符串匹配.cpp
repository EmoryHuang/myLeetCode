/*
 * @Descroption: LeetCode 686. 重复叠加字符串匹配
 * @Author: EmoryHuang
 * @Date: 2021-12-22 08:56:58
 * @Method:
 * 如果 A 的长度小于 B 的长度，这时 B 是 A 的重复子串，
 * 则 A 的重复次数不超过 len(B) / len(A) + 2
 * */


class Solution {
   public:
    int repeatedStringMatch(string a, string b) {
        int n = b.size() / a.size();
        string rep = a;
        // 如果 A 的长度小于 B 的长度，这时 B 是 A 的重复子串，
        // 则 A 的重复次数不超过 len(B) / len(A) + 2
        for (int i = 1; i <= n + 2; i++) {
            if (rep.find(b) != string::npos) return i;
            rep += a;
        }
        return -1;
    }
};