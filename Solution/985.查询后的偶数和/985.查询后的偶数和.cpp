/*
 * @Descroption: LeetCode 985. 查询后的偶数和
 * @Author: EmoryHuang
 * @Date: 2021-10-21 19:35:08
 * @Method:
 * 模拟
 * 计算原数组偶数和 sum，遍历查询
 * 若修改前是偶数，则在 sum 中减去
 * 若修改后变成了偶数，则加上这个数
 */

class Solution {
   public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> ans;
        // 计算原数组偶数和
        for (int num : nums)
            if (num % 2 == 0) sum += num;
        for (auto q : queries) {
            int val = q[0], idx = q[1];
            // 若修改前是偶数，则在 sum 中减去
            if (nums[idx] % 2 == 0) sum -= nums[idx];
            nums[idx] += val;
            // 若修改后变成了偶数
            if (nums[idx] % 2 == 0) sum += nums[idx];
            ans.push_back(sum);
        }
        return ans;
    }
};