/*
 * @Descroption: LeetCode 1870. 准时到达的列车最小时速
 * @Author: EmoryHuang
 * @Date: 2021-07-22 19:33:08
 * @解题思路:
 * 二分法查找能满足的列车最小时速
 * 计算时间时，除了最后一个时间以外向上取整
 * 另外速度可能是10^7
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