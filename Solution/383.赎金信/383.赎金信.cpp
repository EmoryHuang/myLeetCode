/*
 * @Descroption: LeetCode 383. �����
 * @Author: EmoryHuang
 * @Date: 2021-05-20 19:51:37
 * @����˼·:
 * ʹ�ù�ϣ���¼magazine���ַ����ֵĴ�����֮�����ransomNote���������򷵻�false
 */

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;
        for (auto c : magazine) mp[c]++;
        for (auto c : ransomNote) {
            mp[c]--;
            if (mp[c] < 0) return false;
        }
        return true;
    }
};