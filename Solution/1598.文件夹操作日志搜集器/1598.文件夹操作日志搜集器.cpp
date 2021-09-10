/*
 * @Descroption: LeetCode 1598. 文件夹操作日志搜集器
 * @Author: EmoryHuang
 * @Date: 2021-06-20 12:43:00
 * @解题思路:
 * 若 log == './' 不进行操作
 * 若 log == '../ 则 cnt - 1
 * 否则 cnt + 1
 */

class Solution {
   public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for (auto log : logs) {
            if (log == "./")
                ;
            else if (log == "../")
                cnt = max(0, cnt - 1);
            else
                cnt++;
        }
        return cnt;
    }
};