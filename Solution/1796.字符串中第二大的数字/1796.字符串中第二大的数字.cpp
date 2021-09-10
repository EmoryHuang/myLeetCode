/*
 * @Descroption: LeetCode 1796. 字符串中第二大的数字
 * @Author: EmoryHuang
 * @Date: 2021-04-05 18:00:36
 * @解题思路:
 * 遍历字符串，若当前数字大于最大值 `max`，则令 `ans = max` 并且更新最大值，
 * 若当前数字大于第二大值，小于最大值，则更新 `ans` 为当前数字
 */

class Solution {
   public:
    int secondHighest(string s) {
        int len = s.size();
        int ans = -1, max = -1;
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) {
                int num = s[i] - '0';
                if (num > max) {
                    ans = max;                       //第二大值
                    max = num;                       //更新最大值
                } else if (num > ans && num != max)  //若大于第二大值，小于最大值
                    ans = num;
            }
        }
        return ans;
    }
};