/*
 * @Descroption: LeetCode 1732. �ҵ���ߺ���
 * @Author: EmoryHuang
 * @Date: 2021-05-25 12:57:11
 * @����˼·:
 * �������飬��¼��ǰ���θ߶ȣ��������ֵ
 */

class Solution {
   public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, cur = 0;
        for (int g : gain) {
            cur += g;
            ans = max(ans, cur);
        }
        return ans;
    }
};