/*
 * @Descroption: 面试题 17.10. 主要元素
 * @Author: EmoryHuang
 * @Date: 2021-07-09 19:21:36
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
    //     return -1;
    // }

    // 方法二：摩尔投票
    int majorityElement(vector<int>& nums) {
        int res = -1, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) res = num;
            if (res == num)
                cnt++;
            else
                cnt--;
        }
        cnt = 0;
        for (int num : nums)
            if (num == res) cnt++;
        return cnt > nums.size() / 2 ? res : -1;
    }
};