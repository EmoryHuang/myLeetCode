/*
 * @Descroption: LeetCode 287. 寻找重复数
 * @Author: EmoryHuang
 * @Date: 2021-05-22 15:38:00
 * @解题思路:
 * 方法一：哈希表
 *
 * 方法二：快慢指针
 * 因为有重复数字的出现, 所以这个游走必然是成环的,
 * 环的入口就是重复的元素, 即按照寻找链表环入口的思路来做
 */

class Solution {
   public:
    // 方法一：哈希表
    // int findDuplicate(vector<int>& nums) {
    //     map<int, int> mp;
    //     for (int num : nums) {
    //         mp[num]++;
    //         if (mp[num] == 2) return num;
    //     }
    //     return -1;
    // }

    // 方法二：快慢指针
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while (true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow) {
                slow = 0;
                while (fast != slow) {
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return slow;
            }
        }
    }
};