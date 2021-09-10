/*
 * @Descroption: LeetCode 242. ��Ч����ĸ��λ��
 * @Author: EmoryHuang
 * @Date: 2021-05-28 13:19:17
 * @����˼·:
 * ����һ��sort
 * ʹ��sort֮��ֱ���ж��ַ����Ƿ����
 *
 * ��������map
 * ʹ��map�������ж���ĸ�����Ƿ���ͬ
 */

class Solution {
   public:
    // ����һ��sort
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());
    //     if (s == t) return true;
    //     return false;
    // }

    // ��������map
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        map<char, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
            if (it->second != 0) return false;
        return true;
    }
};