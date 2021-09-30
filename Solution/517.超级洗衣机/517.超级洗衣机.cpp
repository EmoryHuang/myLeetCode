/*
 * @Descroption: LeetCode 517. ����ϴ�»�
 * @Author: EmoryHuang
 * @Date: 2021-09-29 09:30:20
 * @Method:
 * ̰��
 * �����ж��Ƿ��ܾ��֣��õ�Ŀ�� target
 * �� num - target < 0 ��ʾ��Ҫ�����߻�ȡ�·�, ������Ҫ�������ó��·�
 * p < 0 ˵����Ҫ���ұ߻�ȡ�·�, p > 0 ˵����Ҫ���ұ��ó��·�
 * ���Ĳ����������� max(num - target, abs(p))
 */

class Solution {
   public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        for (auto num : machines) sum += num;
        if (sum % machines.size()) return -1;
        int target = sum / machines.size();
        int ans = 0, p = 0;
        for (auto num : machines) {
            // �� num - target < 0 ��ʾ��Ҫ�����߻�ȡ�·�, ������Ҫ�������ó��·�
            // p < 0 ˵����Ҫ���ұ߻�ȡ�·�, p > 0 ˵����Ҫ���ұ��ó��·�
            // ���Ĳ����������� max(num - target, abs(p))
            p += num - target;
            ans = max({ans, num - target, abs(p)});
        }
        return ans;
    }
};