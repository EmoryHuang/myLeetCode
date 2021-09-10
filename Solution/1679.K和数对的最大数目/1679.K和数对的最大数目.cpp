/*
 * @Descroption: LeetCode 1679. K 和数对的最大数目
 * @Author: EmoryHuang
 * @Date: 2021-07-20 20:55:06
 * @解题思路:
 * 遍历闭区间内的每一个整数，记录位于区间内的元素的数量
 */

class Solution {
   public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt = 0;
        map<int, int> hash;
        for (int num : nums) {
            if (hash[k - num] == 0)
                hash[num]++;
            else {
                cnt++;
                hash[k - num]--;
            }
        }
        return cnt;
    }
};