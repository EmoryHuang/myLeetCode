/*
 * @Descroption: LeetCode 520. 检测大写字母
 * @Author: EmoryHuang
 * @Date: 2021-04-26 16:12:36
 * @解题思路: 对小写字母的数量进行统计，而后再判断是否符合规范
 */

class Solution {
   public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (auto c : word)
            if (islower(c)) cnt++;
        // 全小写/全大写/首字母大写
        if (cnt == word.size() || cnt == 0 || (isupper(word[0]) && cnt == word.size() - 1))
            return true;
        return false;
    }
};