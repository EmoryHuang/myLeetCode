/*
 * @Descroption: LeetCode 401. 二进制手表
 * @Author: EmoryHuang
 * @Date: 2021-04-29 19:02:36
 * @解题思路:
 * 直接遍历 0:00 -> 12:00 每个时间有多少个 1
 */

class Solution {
   public:
    int count(int num) {
        int cnt = 0;
        while (num) {
            num = num & (num - 1);
            cnt++;
        }
        return cnt;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (count(i) + count(j) == turnedOn)
                    ans.push_back(to_string(i) + ":" + (j < 10 ? "0" : "") + to_string(j));
            }
        }
        return ans;
    }
};