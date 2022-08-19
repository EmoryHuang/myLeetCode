/*
 * @Descroption: LeetCode 1832. 判断句子是否为全字母句
 * @Author: EmoryHuang
 * @Date: 2021-04-21 15:19:36
 * @解题思路:
 * 开辟数组用于计数，之后在遍历一遍计数数组，也可以使用 set 等容器
 */

class Solution {
   public:
    bool checkIfPangram(string sentence) {
        vector<int> count(26, 0);
        for (int i = 0; i < sentence.size(); i++) count[sentence[i] - 'a']++;
        for (int i = 0; i < 26; i++)
            if (count[i] == 0) return false;
        return true;
    }
};