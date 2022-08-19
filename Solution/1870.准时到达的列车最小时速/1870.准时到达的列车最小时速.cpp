/*
 * @Descroption: LeetCode 1870. ׼ʱ������г���Сʱ��
 * @Author: EmoryHuang
 * @Date: 2021-07-22 19:33:08
 * @����˼·:
 * ���ַ�������������г���Сʱ��
 * ����ʱ��ʱ���������һ��ʱ����������ȡ��
 * �����ٶȿ�����10^7
 */

class Solution {
   public:
    bool check(vector<int>& dist, double hour, int speed) {
        double cnt = 0;
        for (int i = 0; i < dist.size() - 1; i++) cnt += ceil(1.0 * dist[i] / speed);
        cnt += 1.0 * dist.back() / speed;
        return cnt <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 10000001;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(dist, hour, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l <= 10000000 ? l : -1;
    }
};