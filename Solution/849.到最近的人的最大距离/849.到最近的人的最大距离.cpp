/*
 * @Descroption: LeetCode 849. 到最近的人的最大距离
 * @Author: EmoryHuang
 * @Date: 2021-06-13 15:25:00
 * @解题思路:
 * 寻找最长的连续0，在头尾部分特殊处理
 */

class Solution {
   public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int start = -1, ans = 0;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (start == -1)  // 第一个数
                    ans = i;
                else
                    ans = max(ans, (i - start) / 2);
                start = i;
            }
        }
        ans = max(n - start - 1, ans);  // 最后一个数
        return ans;
    }
};