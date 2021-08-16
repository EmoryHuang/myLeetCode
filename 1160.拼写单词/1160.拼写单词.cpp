/*
 * @Descroption: LeetCode 1160. ƴд����
 * @Author: EmoryHuang
 * @Date: 2021-08-16 20:38:55
 * @Method:
 * ����������������߽���Ҳ�����ڣ���˵���ҵ��˳���
 */

class Solution {
   public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> chars_cnt;
        for (char c : chars) chars_cnt[c]++;
        int ans = 0;
        for (auto word : words) {
            bool flag = true;
            unordered_map<char, int> word_cnt;
            for (auto c : word) word_cnt[c]++;
            for (auto c : word) {
                if (chars_cnt[c] < word_cnt[c]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans += word.size();
        }
        return ans;
    }
};