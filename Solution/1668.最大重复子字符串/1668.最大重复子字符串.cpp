/*
 * @Descroption: LeetCode 1668. 最大重复子字符串
 * @Author: EmoryHuang
 * @Date: 2021-05-19 20:28:31
 * @解题思路:
 * 简单题，如果找到word，则查找word的重复
 */

class Solution {
   public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        string tmp = word;
        while (sequence.find(word) != string::npos) {
            word += tmp;
            ans++;
        }
        return ans;
    }
};