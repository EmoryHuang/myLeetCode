/*
 * @Descroption: LeetCode 1668. ����ظ����ַ���
 * @Author: EmoryHuang
 * @Date: 2021-05-19 20:28:31
 * @����˼·:
 * ���⣬����ҵ�word�������word���ظ�
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