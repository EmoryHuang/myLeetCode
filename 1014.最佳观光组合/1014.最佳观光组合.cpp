/*
 * @Descroption: LeetCode 1014. ��ѹ۹����
 * @Author: EmoryHuang
 * @Date: 2021-05-21 14:03:00
 * @����˼·:
 * ��values[i] + values[j] + i - j����Ϊvalues[i] + i + values[j]  - j
 * Ȼ��ֱ���values[i] + i��values[j]  - j�����ֵ
 */
 
class Solution {
   public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxv = INT_MIN, left = values[0];
        for (int i = 1; i < values.size(); i++) {
            maxv = max(maxv, left + values[i] - i);  // �������ֵ
            left = max(left, values[i] + i);         // ����values[i] + i
        }
        return maxv;
    }
};