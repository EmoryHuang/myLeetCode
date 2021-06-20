/*
 * @Descroption: LeetCode 1598. �ļ��в�����־�Ѽ���
 * @Author: EmoryHuang
 * @Date: 2021-06-20 12:43:00
 * @����˼·:
 * �� log == './' �����в���
 * �� log == '../ �� cnt - 1
 * ���� cnt + 1
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