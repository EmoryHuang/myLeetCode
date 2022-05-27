/*
 * @Descroption: 面试题 17.11. 单词距离
 * @Author: EmoryHuang
 * @Date: 2022-05-27 08:52:55
 * @Method:
 * 一次遍历 + 双指针
 * 记录单词出现的位置，取最短距离
 */


class Solution {
   public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int ans = INT_MAX;
        int index1 = -1, index2 = -1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1)
                index1 = i;
            else if (words[i] == word2)
                index2 = i;
            if (index1 >= 0 && index2 >= 0) ans = min(ans, abs(index1 - index2));
        }
        return ans;
    }
};