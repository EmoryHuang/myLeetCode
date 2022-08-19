/*
 * @Descroption: LeetCode 1423. 可获得的最大点数
 * @Author: EmoryHuang
 * @Date: 2021-09-17 19:28:03
 * @Method:
 * 滑动窗口
 * 滑动窗口大小为 n - k
 * 保证滑动窗口内元素最小，也就是剩下的元素最小
 */

class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for (int i = 0; i < n - k; i++) sum += cardPoints[i];
        int ans = sum;
        for (int i = n - k; i < n; i++) {
            sum += cardPoints[i] - cardPoints[i - n + k];
            ans = min(ans, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - ans;
    }
};