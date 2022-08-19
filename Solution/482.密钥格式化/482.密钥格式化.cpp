/*
 * @Descroption: LeetCode 482. ��Կ��ʽ��
 * @Author: EmoryHuang
 * @Date: 2021-04-24 15:26:36
 * @����˼·:
 * �����ַ������������з� '-' �ַ������룬֮���ٴα����Ӻ���ǰÿ�� k ���ַ����� '-'
 */

class Solution {
   public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        for (int i = 0; i < s.size(); i++)  // �������з� '-' �ַ�������
            if (s[i] != '-') ans += toupper(s[i]);
        for (int i = ans.size() - k; i > 0; i -= k) {  // �Ӻ���ǰ���� '-'
            ans.insert(i, "-");
        }
        return ans;
    }
};