/*
 * @Descroption: LeetCode 1784. ���������ַ����ֶ�
 * @Author: EmoryHuang
 * @Date: 2021-08-05 20:01:25
 * @Method:
 * ���⣬��¼���ֱ仯�Ĵ���
 */

class Solution {
   public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        for (int i = 1; i < s.size(); i++)
            if (s[i] != s[i - 1]) cnt++;
        return cnt <= 1;
    }
};