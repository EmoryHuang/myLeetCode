/*
 * @Descroption: LeetCode 1936. ����������̨����
 * @Author: EmoryHuang
 * @Date: 2021-07-21 21:10:05
 * @����˼·:
 * ̰��
 * ά����ǰλ�� pos
 * ����ܵ������̨��, ��������̨��
 * ������ܵ������̨�ף����̨�׵��ܵ���Ϊֹ
 */

class Solution {
   public:
    int addRungs(vector<int>& rungs, int dist) {
        int pos = 0, cnt = 0;
        for (int rung : rungs) {
            // ������ܵ������̨��
            // ̰�����̨��
            if (pos + dist < rung) cnt += (rung - pos - 1) / dist;
            pos = rung;  // �������̨��
        }
        return cnt;
    }
};