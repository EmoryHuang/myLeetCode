/*
 * @Descroption: LeetCode 169. 多数元素
 * @Author: EmoryHuang
 * @Date: 2021-07-11 14:37:43
 * @解题思路:
 * 方法一：哈希表
 * 使用一个哈希表记录元素的数量
 * 方法二：摩尔投票
 * 摩尔投票：每次将两个不同的元素进行「抵消」，如果最后有元素剩余，则「可能」为元素个数大于总数一半的那个
 * 之后再进行一次遍历，检查这个「可能」的主要元素 x 的出现次数是否超过总数一半
 */

class Solution {
   public:
    // 方法一：哈希表
    // int majorityElement(vector<int>& nums) {
    //     map<int, int> hash;
    //     for (int num : nums) {
    //         hash[num]++;
    //         if (hash[num] > nums.size() / 2) return num;
    //     }
    //     return 0;
    // }

    // 方法二：摩尔投票
    int majorityElement(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) ans = nums[i];
            if (ans == nums[i])
                cnt++;
            else
                cnt--;
        }
        cnt = 0;
        for (int num : nums)
            if (num == ans) cnt++;
        return cnt > nums.size() / 2 ? ans : 0;
    }
};