/*
 * @Descroption: LeetCode 1014. 最佳观光组合
 * @Author: EmoryHuang
 * @Date: 2021-05-21 14:03:00
 * @解题思路:
 * 将values[i] + values[j] + i - j划分为values[i] + i + values[j]  - j
 * 然后分别求values[i] + i和values[j]  - j的最大值
 */
 
class Solution {
   public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxv = INT_MIN, left = values[0];
        for (int i = 1; i < values.size(); i++) {
            maxv = max(maxv, left + values[i] - i);  // 更新最大值
            left = max(left, values[i] + i);         // 更新values[i] + i
        }
        return maxv;
    }
};