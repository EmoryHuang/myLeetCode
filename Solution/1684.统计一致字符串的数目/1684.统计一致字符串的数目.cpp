/*
 * @Descroption: LeetCode 1684. 统计一致字符串的数目
 * @Author: EmoryHuang
 * @Date: 2021-09-22 16:44:05
 * @Method:
 * 简单题，依次判断每个单词所含的字符是否在 allowed 中
 */

class Solution {
   public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        for (auto word : words) {
            bool flag = 1;
            for (auto c : word) {
                if (allowed.find(c) == string::npos) {
                    flag = 0;
                    break;
                }
            }
            if (flag) ans += 1;
        }
        return ans;
    }
};