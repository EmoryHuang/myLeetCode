/*
 * @Descroption: ��ָ Offer 05. �滻�ո�
 * @Author: EmoryHuang
 * @Date: 2021-06-28 16:42:00
 * @����˼·:
 * ���⣬�滻�ո񣬱�������ֱ�� replace
 */

class Solution {
   public:
    string replaceSpace(string s) {
        while (s.find(' ') != string::npos) s.replace(s.find(' '), 1, "%20");
        return s;
    }
};