/*
 * @Descroption: LeetCode 398. 随机数索引
 * @Author: EmoryHuang
 * @Date: 2022-04-25 08:51:17
 * @Method:
 * 水塘抽样
 * 当第 i 次遇到值为 target 的元素时, 随机选择区间 [0,i) 内的一个整数
 * 如果其等于 0, 则将返回值置为该元素的下标, 否则返回值不变
 */

class Solution {
   public:
    vector<int> nums;
    Solution(vector<int>& _nums) { nums = _nums; }

    int pick(int target) {
        int res = -1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                cnt++;
                if (rand() % cnt == 0) res = i;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */