/*
 * @Descroption: LeetCode 1221. �ָ�ƽ���ַ���
 * @Author: EmoryHuang
 * @Date: 2021-08-23 19:20:53
 * @Method:
 * ̰�ģ�����L��R�ĸ�����������������¼����������
 */

class Solution {
   public:
    int balancedStringSplit(string s) {
        int l = 0, r = 0, ans = 0;
        for (auto c : s) {
            if (c == 'L') l++;
            if (c == 'R') r++;
            if (l == r) {
                ans++;
                l = r = 0;
            }
        }
        return ans;
    }
};