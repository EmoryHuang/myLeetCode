/*
 * @Descroption: LeetCode 2001. �ɻ������ε�����
 * @Author: EmoryHuang
 * @Date: 2021-10-08 19:10:58
 * @Method:
 * ��ϣ���¼��߱���ͬ�ľ��ε�����
 */


class Solution {
   public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> hash;
        for (auto r : rectangles) hash[(double)r[0] / r[1]]++;
        unordered_map<double, int>::iterator it;
        long long ans = 0;
        for (it = hash.begin(); it != hash.end(); it++) {
            int n = it->second;
            if (n > 0) ans += (long long)n * (n - 1) / 2;
        }
        return ans;
    }
};