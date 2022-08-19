/*
 * @Descroption: LeetCode 1513. ���� 1 ���Ӵ���
 * @Author: EmoryHuang
 * @Date: 2021-08-11 14:43:15
 * @Method:
 * ���⣬��ѧ��ͳ�������ִ�����ɵĽ��� 1 ���Ӵ���
 */

class Solution {
   public:
    int numSub(string s) {
        long ans = 0, cnt = 0;
        for (auto c : s) {
            if (c == '1')
                ans += ++cnt;
            else
                cnt = 0;
        }
        return ans % 1000000007;
    }
};