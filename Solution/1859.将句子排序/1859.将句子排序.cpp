/*
 * @Descroption: LeetCode 1859. ����������
 * @Author: EmoryHuang
 * @Date: 2021-05-30 10:08:00
 * @����˼·:
 * ���⣬ֱ�Ӱѵ���β�������ֵ��±��ã������ϣ��
 */

class Solution {
   public:
    string sortSentence(string s) {
        vector<string> order(10);
        string str = " ";
        for (auto c : s) {
            if (isalpha(c)) str += c;
            if (isdigit(c)) {
                order[c - '0'] = str;
                str = " ";
            }
        }
        string ans;
        for (auto c : order) ans += c;
        ans.erase(0, 1);  // ȥ����һ���ո�
        return ans;
    }
};