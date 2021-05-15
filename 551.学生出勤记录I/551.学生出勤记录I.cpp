/*
 * @Descroption: LeetCode 551. 学生出勤记录 I
 * @Author: EmoryHuang
 * @Date: 2021-05-04 14:30:36
 * @解题思路:
 * 简单题，遍历一遍寻找 `A` 的个数，再通过 `find` 寻找连续 3 个 `LLL`
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