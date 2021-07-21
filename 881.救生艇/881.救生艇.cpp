/*
 * @Descroption: LeetCode 881. 救生艇
 * @Author: EmoryHuang
 * @Date: 2021-07-21 20:18:39
 * @解题思路:
 * 双指针 + 贪心
 * 如果最左边和最右边的人能上船，那么这两个人就走
 * 如果最左边和最右边的人不能上船，最右边的人单独走
 */

class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int cnt = 0, l = 0, r = people.size() - 1;
        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                // 如果最左边和最右边的人能上船
                l++;
                r--;
                cnt++;
            } else {
                // 如果最左边和最右边的人不能上船，最右边的人单独走
                r--;
                cnt++;
            }
        }
        return cnt;
    }
};