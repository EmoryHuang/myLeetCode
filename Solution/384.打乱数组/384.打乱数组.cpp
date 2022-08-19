/*
 * @Descroption: LeetCode 384. 打乱数组
 * @Author: EmoryHuang
 * @Date: 2021-11-22 18:34:45
 * @Method:
 * 洗牌算法
 * 在 [i,n) 中随机抽取一个下标 j
 * 将第 i 个元素与第 j 个元素交换
 */

class Solution {
   public:
    vector<int> __nums;
    Solution(vector<int>& nums) { __nums = nums; }

    vector<int> reset() { return __nums; }

    vector<int> shuffle() {
        vector<int> res = __nums;
        for (int i = 0; i < res.size(); i++) {
            int j = rand() % (i + 1);
            swap(res[i], res[j]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */