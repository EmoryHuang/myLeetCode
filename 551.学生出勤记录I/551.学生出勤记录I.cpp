/*
 * @Descroption: LeetCode 551. ѧ�����ڼ�¼ I
 * @Author: EmoryHuang
 * @Date: 2021-05-04 14:30:36
 * @����˼·:
 * ���⣬����һ��Ѱ�� `A` �ĸ�������ͨ�� `find` Ѱ������ 3 �� `LLL`
 */

class Solution {
   public:
    bool checkRecord(string s) {
        int countA = 0;
        int countL = s.find("LLL");
        for (auto c : s)
            if (c == 'A') countA++;
        return countA < 2 && countL == -1;
    }
};