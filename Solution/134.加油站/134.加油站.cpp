/*
 * @Descroption: LeetCode 134. ����վ
 * @Author: EmoryHuang
 * @Date: 2021-05-13 14:47:36
 * @����˼·:
 * �����ʼվ���������С�� 0����ô������Ϊ���
 * ���վ���Ե�ЧΪһ��վ��������ܵ����ô��һվ��Ϊ���
 * ����ܺͱ�����ڵ��� 0
 */

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int cur = 0, total = 0, start = 0;
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            cur += gas[i] - cost[i];
            if (cur < 0) {  // һ��վ���������С��0
                cur = 0;
                start = i + 1;  // ��һվ��Ϊ���
            }
        }
        return total < 0 ? -1 : start;  // �ܺͱ�����ڵ���0
    }
};