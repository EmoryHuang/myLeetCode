/*
 * @Descroption: LeetCode 1184. ����վ��ľ���
 * @Author: EmoryHuang
 * @Date: 2021-05-26 16:17:17
 * @����˼·:
 * ��Ϊ����վ�ǻ��Σ����ֻ�������߷��������߻��߷�����
 * ֻҪȡ��Сֵ����
 */

class Solution {
   public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0, l, r;
        for (int num : distance) sum += num;
        l = min(start, destination);  // ��СֵΪ���
        r = max(start, destination);  // �ϴ�ֵΪ�յ�
        int ans = 0;
        for (int i = 0; i < distance.size(); i++)
            if (i >= l && i < r) ans += distance[i];
        return min(ans, sum - ans);  // �����߻�����
    }
};