/*
 * @Descroption: LeetCode 1544. �����ַ���
 * @Author: EmoryHuang
 * @Date: 2021-04-22 14:29:36
 * @����˼·:
 * �����ַ�������`ans`�����һ��Ԫ���뵱ǰ�ַ��Ƚϣ���`ans`�ǿղ������ߵ� ACSII ��� 32��
 * ��ȥ��`ans`�е����һ��Ԫ�أ��������
 */

class Solution {
   public:
    string makeGood(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (!ans.empty() && abs(ans.back() - s[i]) == 32)
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};