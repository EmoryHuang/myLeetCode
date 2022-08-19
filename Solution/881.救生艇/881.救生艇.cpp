/*
 * @Descroption: LeetCode 881. 救生艇
 * @Author: EmoryHuang
 * @Date: 2021-08-26 15:56:33
 * @Method:
 * 双指针 + 排序
 * 首先对数组进行排序，维护两个指针l和r，分别指向头尾
 * 若 people[l] + people[r] <= limit 说明能够载2人，指针分别向右，向左更新
 * 否则，people[r] 需要单独安排船，右指针向左移动
 */

class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0, l = 0, r = people.size() - 1;
        while (l <= r) {
            if (people[l] + people[r] <= limit) l++;
            r--;
            ans++;
        }
        return ans;
    }
};