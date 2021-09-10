/*
 * @Descroption: LeetCode 1456. �����Ӵ���Ԫ���������Ŀ
 * @Author: EmoryHuang
 * @Date: 2021-08-08 14:49:49
 * @Method:
 * �������ڣ�ͳ�ƴ�����Ԫ����ĸ����Ŀ����¼���ֵ
 */

class Solution {
   public:
    int maxVowels(string s, int k) {
        set<char> ls = {'a', 'e', 'i', 'o', 'u'};
        int l = 0, r = 0;
        int ans = 0, cnt = 0;
        while (r < s.size()) {
            if (ls.count(s[r++])) {
                cnt++;
                ans = max(ans, cnt);
            }
            if (r - l >= k)
                if (ls.count(s[l++])) cnt -= 1;
        }
        return ans;
    }
};