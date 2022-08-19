/*
 * @Descroption: LeetCode 1893. ����Ƿ�����������������������
 * @Author: EmoryHuang
 * @Date: 2021-07-20 20:15:26
 * @����˼·:
 * �����������ڵ�ÿһ����������¼λ�������ڵ�Ԫ�ص�����
 */

class Solution {
   public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; i++)
            for (auto range : ranges)
                if (i >= range[0] && i <= range[1]) {
                    cnt++;
                    break;
                }
        return cnt == right - left + 1;
    }
};