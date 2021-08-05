/*
 * @Descroption: LeetCode 1790. ��ִ��һ���ַ��������ܷ�ʹ�����ַ������
 * @Author: EmoryHuang
 * @Date: 2021-08-05 20:12:43
 * @Method:
 * ���⣬��¼��Ӧλ�ò���ͬ��Ԫ�ظ���
 */

class Solution {
   public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        vector<int> mp(26);
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            mp[s1[i] - 'a']++;
            mp[s2[i] - 'a']--;
            if (s1[i] != s2[i]) cnt++;
        }
        for (int num : mp)
            if (num != 0) return false;
        return cnt == 2;
    }
};