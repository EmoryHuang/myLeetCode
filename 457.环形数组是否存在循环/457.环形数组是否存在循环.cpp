/*
 * @Descroption: LeetCode 457. 环形数组是否存在循环
 * @Author: EmoryHuang
 * @Date: 2021-08-07 14:22:09
 * @Method:
 * 模拟
 * 从每个下标 i 进行出发检查，如果以某个下标 i 为出发点发现了「循环」，返回 True，否则返回 False
 */

class Solution {
   public:
    int n;
    bool check(vector<int>& nums, int start) {
        int cur = start;
        int cnt = 1;  // 记录过程中扫描过的下标数量
        while (true) {
            if (cnt > n) return false;
            int next = ((cur + nums[cur]) % n + n) % n;
            // 不全是正数或者负数
            if (nums[start] > 0 && nums[next] < 0) return false;
            if (nums[start] < 0 && nums[next] > 0) return false;
            if (start == next) return cnt > 1;  // 找到了与起点相同的下标
            cur = next;
            cnt++;
        }
    }
    bool circularArrayLoop(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < n; i++)
            if (check(nums, i)) return true;
        return false;
    }
};