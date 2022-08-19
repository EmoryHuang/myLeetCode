/*
 * @Descroption: LeetCode 1491. 去掉最低工资和最高工资后的工资平均值
 * @Author: EmoryHuang
 * @Date: 2021-04-21 15:49:36
 * @解题思路:
 * 简单题，减去最大最小值，求平均值
 */

class Solution {
   public:
    double average(vector<int>& salary) {
        int sum = 0, maxs = INT_MIN, mins = INT_MAX;
        for (int i = 0; i < salary.size(); i++) {
            sum += salary[i];
            maxs = max(maxs, salary[i]);
            mins = min(mins, salary[i]);
        }
        return 1.0 * (sum - maxs - mins) / (salary.size() - 2);
    }
};