/*
 * @Descroption: LeetCode 1725. �����γ���������εľ�����Ŀ
 * @Author: EmoryHuang
 * @Date: 2022-02-04 10:22:58
 * @Method:
 * ���⣬ö��ÿ���������г�����������α߳���Ȼ�������ֵ������
 */

class Solution {
   public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int ans = 0, max_len = 0;
        for (auto rect : rectangles) {
            int w = rect[0], l = rect[1];
            int e = min(w, l);
            if (e > max_len) {
                max_len = e;
                ans = 1;
            } else if (e == max_len) {
                ans++;
            }
        }
        return ans;
    }
};