/*
 * @Descroption: LeetCode 1408. 数组中的字符串匹配
 * @Author: EmoryHuang
 * @Date: 2021-06-23 12:35:00
 * @解题思路:
 * 暴力，遍历每个元素，在其他元素中查找是否为子串
 */

class Solution {
   public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (auto word : words) {
            for (int i = 0; i < words.size(); i++) {
                if (word != words[i] && words[i].find(word) != string::npos) {
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};